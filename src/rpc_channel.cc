#include "rpc_channel.h"

#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <string>

#include "logger.h"
#include "rpc_application.h"
#include "rpc_controller.h"
#include "rpc_header.pb.h"
#include "zookeeper_util.h"

// 所有通过stub代理对象调用的rpc方法，都走到这里了，统一做rpc方法调用的数据数据序列化和网络发送
// 1. 组合最终要发送的字符串send_rpc_str,其组成如下：
// 4bytes(rpc_header长度)rpc_header(服务名、方法名、request序列化后长度)request
// 即header_size + service_name method_name args_size + args
// 2. 从zookeeper server获取该服务对应方法的url（ip:port)
// 3. socket连接到remote url，并发送send_rpc_str
// 4. recv阻塞直到收到数据,反序列化到response对象里
void RpcChannel::CallMethod(const google::protobuf::MethodDescriptor* method,
                            google::protobuf::RpcController* controller,
                            const google::protobuf::Message* request,
                            google::protobuf::Message* response,
                            google::protobuf::Closure* done) {
  const google::protobuf::ServiceDescriptor* sd = method->service();
  std::string service_name = sd->name();
  std::string method_name = method->name();

  // 获取request参数的序列化字符串长度
  uint32_t args_size = 0;
  std::string args_str;
  if (request->SerializeToString(&args_str)) {
    args_size = args_str.size();
  } else {
    controller->SetFailed("serialize request error!");
    LOG_ERROR("request serialize request error!");
    return;
  }

  // 定义RPC的请求header
  myrpc::RpcHeader rpc_header;
  rpc_header.set_service_name(service_name);
  rpc_header.set_method_name(method_name);
  rpc_header.set_args_size(args_size);

  uint32_t header_size = 0;
  std::string rpc_header_str;
  if (rpc_header.SerializeToString(&rpc_header_str)) {
    header_size = rpc_header_str.size();
  } else {
    controller->SetFailed("serialize rpc header error!");
    LOG_ERROR("serialize rpc header error!");
    return;
  }

  // 组织待发送的RPC请求的字符串
  std::string send_rpc_str;
  send_rpc_str.insert(0, std::string((char*)&header_size, 4));  // header_size
  send_rpc_str += rpc_header_str;                               // rpcheader
  send_rpc_str += args_str;                                     // args

  // rpc调用方想调用service_name的method_name服务，需要查询zk上该服务所在的host信息
  ZkClient zkCli;
  zkCli.Connect();
  //  /UserServiceRpc/Login
  std::string method_path = "/" + service_name + "/" + method_name;
  // 127.0.0.1:8000
  std::string host_data = zkCli.GetData(method_path.c_str());
  if (host_data == "") {
    controller->SetFailed(method_path + " is not exist!");
    LOG_ERROR("%s is not exist!", method_path);
    return;
  }
  int idx = host_data.find(":");
  if (idx == -1) {
    controller->SetFailed(method_path + " address is invalid!");
    LOG_ERROR("%s address is invalid!", method_path);
    return;
  }
  std::string ip = host_data.substr(0, idx);
  uint16_t port =
      atoi(host_data.substr(idx + 1, host_data.size() - idx).c_str());

  // 使用tcp编程，完成rpc方法的远程调用
  int clientfd = socket(AF_INET, SOCK_STREAM, 0);
  if (-1 == clientfd) {
    char errtxt[512] = {0};
    sprintf(errtxt, "create socket error! errno:%d", errno);
    controller->SetFailed(errtxt);
    LOG_ERROR("create socket error! errno:%d", errno);
    return;
  }
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = inet_addr(ip.c_str());

  // 连接rpc服务节点
  if (-1 ==
      connect(clientfd, (struct sockaddr*)&server_addr, sizeof(server_addr))) {
    close(clientfd);
    char errtxt[512] = {0};
    sprintf(errtxt, "connect error! errno:%d", errno);
    controller->SetFailed(errtxt);
    LOG_ERROR("connect error! errno:%d", errno);
    return;
  }

  // 发送rpc请求
  if (-1 == send(clientfd, send_rpc_str.c_str(), send_rpc_str.size(), 0)) {
    close(clientfd);
    char errtxt[512] = {0};
    sprintf(errtxt, "send error! errno:%d", errno);
    controller->SetFailed(errtxt);
    LOG_ERROR("send error! errno:%d", errno);
    return;
  }

  // 接收rpc请求的响应值
  char recv_buf[1024] = {0};
  int recv_size = 0;
  if (-1 == (recv_size = recv(clientfd, recv_buf, 1024, 0))) {
    close(clientfd);
    char errtxt[512] = {0};
    sprintf(errtxt, "recv error! errno:%d", errno);
    controller->SetFailed(errtxt);
    LOG_ERROR("recv error! errno:%d", errno);
    return;
  }

  // 反序列化rpc调用的响应数据
  // std::string response_str(recv_buf, 0, recv_size); //
  // bug出现问题，recv_buf中遇到\0后面的数据就存不下来了，导致反序列化失败 if
  // (!response->ParseFromString(response_str))
  if (!response->ParseFromArray(recv_buf, recv_size)) {
    close(clientfd);
    char errtxt[512] = {0};
    LOG_ERROR("parse error! response_str:%s", recv_buf);
    sprintf(errtxt, "parse error! response_str:%s", recv_buf);
    controller->SetFailed(errtxt);
    return;
  }
  close(clientfd);
}
// TODO: 短连接 -> 长连接？
// TODO: 同步阻塞 -> 异步非阻塞？