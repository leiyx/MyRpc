#include "rpc_server.h"

#include "logger.h"
#include "rpc_application.h"
#include "rpc_header.pb.h"
#include "zookeeper_util.h"

void RpcServer::NotifyService(google::protobuf::Service *service) {
  ServiceInfo service_info;

  const google::protobuf::ServiceDescriptor *pserviceDesc =
      service->GetDescriptor();
  std::string service_name = pserviceDesc->name();
  int method_count = pserviceDesc->method_count();

  LOG_INFO("要发布的RPC服务名:%s,有%d个RPC方法", service_name.c_str(),
           method_count);
  for (int i = 0; i < method_count; ++i) {
    const google::protobuf::MethodDescriptor *pmethodDesc =
        pserviceDesc->method(i);
    std::string method_name = pmethodDesc->name();
    service_info.method_map_.insert({method_name, pmethodDesc});

    LOG_INFO("RPC服务%s中，第%d个RPC方法:%s", service_name.c_str(), i + 1,
             method_name.c_str());
  }
  service_info.service_ = service;
  service_map_.insert({service_name, service_info});
}

void RpcServer::Run(int thread_num) {
  // 读取配置文件rpcserver的信息
  std::string ip =
      RpcApplication::GetInstance().GetConfig().GetConfigOpt("rpcserverip");
  uint16_t port = atoi(RpcApplication::GetInstance()
                           .GetConfig()
                           .GetConfigOpt("rpcserverport")
                           .c_str());
  muduo::net::InetAddress address(ip, port);

  muduo::net::TcpServer server(&loop_, address, "RpcServer");

  // 绑定连接回调和消息读写回调方法  分离了网络代码和业务代码
  server.setConnectionCallback(
      std::bind(&RpcServer::OnConnection, this, std::placeholders::_1));
  server.setMessageCallback(
      std::bind(&RpcServer::OnMessage, this, std::placeholders::_1,
                std::placeholders::_2, std::placeholders::_3));

  server.setThreadNum(thread_num);

  // 把当前rpc节点上要发布的服务全部注册到zk上面，让rpc client可以从zk上发现服务
  // session timeout   30s     zkclient 网络I/O线程  1/3 * timeout
  // 时间发送ping消息
  ZkClient zkCli;
  zkCli.Connect();
  // service_name为永久性节点    method_name为临时性节点
  for (auto &sp : service_map_) {
    // /service_name   /UserServiceRpc
    std::string service_path = "/" + sp.first;
    zkCli.Create(service_path.c_str(), nullptr, 0);
    for (auto &mp : sp.second.method_map_) {
      // /service_name/method_name   /UserServiceRpc/Login
      // 存储当前这个rpc服务节点主机的ip和port
      std::string method_path = service_path + "/" + mp.first;
      char method_path_data[128] = {0};
      sprintf(method_path_data, "%s:%d", ip.c_str(), port);
      // ZOO_EPHEMERAL表示znode是一个临时性节点
      zkCli.Create(method_path.c_str(), method_path_data,
                   strlen(method_path_data), ZOO_EPHEMERAL);
    }
  }
  LOG_INFO("RpcServer开启服务，地址在%s:%d", ip, port);
  // 启动网络服务
  server.start();
  loop_.loop();
}

void RpcServer::OnConnection(const muduo::net::TcpConnectionPtr &conn) {
  if (!conn->connected()) {
    conn->shutdown();
  }
}

/*
在框架内部，RpcServer和RpcConsumer协商好之间通信用的protobuf数据类型
service_name method_name args
定义proto的message类型，进行数据头的序列化和反序列化 service_name method_name
args_size 16UserServiceLoginzhang san123456

header_size(4个字节) + header_str + args_str
10 "10"
10000 "1000000"
std::string   insert和copy方法
*/
// 已建立连接用户的读写事件回调
void RpcServer::OnMessage(const muduo::net::TcpConnectionPtr &conn,
                          muduo::net::Buffer *buffer, muduo::Timestamp) {
  // 网络上接收的远程rpc调用请求的字符流    Login args
  std::string recv_buf = buffer->retrieveAllAsString();

  // 从字符流中读取前4个字节的内容
  uint32_t header_size = 0;
  recv_buf.copy((char *)&header_size, 4, 0);

  // 根据header_size读取数据头的原始字符流，反序列化数据，得到rpc请求的详细信息
  std::string rpc_header_str = recv_buf.substr(4, header_size);
  myrpc::RpcHeader rpc_header;
  std::string service_name;
  std::string method_name;
  uint32_t args_size;
  if (rpc_header.ParseFromString(rpc_header_str)) {
    // 数据头反序列化成功
    service_name = rpc_header.service_name();
    method_name = rpc_header.method_name();
    args_size = rpc_header.args_size();
  } else {
    // 数据头反序列化失败
    LOG_ERROR("rpc_header_str:%s parse error!", rpc_header_str);
    return;
  }

  // 获取rpc方法参数的字符流数据
  std::string args_str = recv_buf.substr(4 + header_size, args_size);

  // 获取service对象和method对象
  auto it = service_map_.find(service_name);
  if (it == service_map_.end()) {
    LOG_ERROR("%s is not exist!", service_name);
    return;
  }

  auto mit = it->second.method_map_.find(method_name);
  if (mit == it->second.method_map_.end()) {
    LOG_ERROR("%s:%s is not exist!", service_name, method_name);
    return;
  }
  // 获取service对象
  google::protobuf::Service *service = it->second.service_;
  // 获取method对象描述符
  const google::protobuf::MethodDescriptor *method = mit->second;

  // 生成rpc方法调用的请求request和响应response参数
  google::protobuf::Message *request =
      service->GetRequestPrototype(method).New();
  if (!request->ParseFromString(args_str)) {
    LOG_ERROR("request parse error, content:%s", args_str);
    return;
  }
  google::protobuf::Message *response =
      service->GetResponsePrototype(method).New();

  // 给下面的method方法的调用，绑定一个Closure的回调函数
  google::protobuf::Closure *done =
      google::protobuf::NewCallback<RpcServer,
                                    const muduo::net::TcpConnectionPtr &,
                                    google::protobuf::Message *>(
          this, &RpcServer::SendRpcResponse, conn, response);

  // 在框架上根据远端rpc请求，调用当前rpc节点上发布的方法
  // new UserService().Login(controller, request, response, done)
  service->CallMethod(method, nullptr, request, response, done);
}

// Closure的回调操作，用于序列化rpc的响应和网络发送
void RpcServer::SendRpcResponse(const muduo::net::TcpConnectionPtr &conn,
                                google::protobuf::Message *response) {
  std::string response_str;
  if (response->SerializeToString(&response_str))
    // 序列化成功后，通过网络把rpc方法执行的结果发送会rpc的调用方
    conn->send(response_str);
  else
    LOG_ERROR("response对象序列化失败");
  conn->shutdown();  // 模拟http的短链接服务，由RpcServer主动断开连接
}