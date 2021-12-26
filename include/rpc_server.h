#ifndef RPC_SERVER_H
#define RPC_SERVER_H
#include <google/protobuf/descriptor.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpConnection.h>
#include <muduo/net/TcpServer.h>

#include <functional>
#include <string>
#include <unordered_map>

#include "google/protobuf/service.h"

// 框架提供的专门发布RPC服务的网络对象类
class RpcServer {
 public:
  // 发布RPC服务的函数接口
  void NotifyService(google::protobuf::Service *service);
  // 启动RPC服务节点，开始提供RPC远程网络调用服务
  void Run(int thread_num);

 private:
  // 连接建立、断开回调
  void OnConnection(const muduo::net::TcpConnectionPtr &);
  // 已建立连接的读写事件回调
  void OnMessage(const muduo::net::TcpConnectionPtr &, muduo::net::Buffer *,
                 muduo::Timestamp);
  // Closure的回调操作，用于序列化RPC方法的response和网络发送
  void SendRpcResponse(const muduo::net::TcpConnectionPtr &,
                       google::protobuf::Message *);

 private:
  muduo::net::EventLoop loop_;

  // service服务类型信息，存储了RPC服务内的所有RPC方法的相关信息
  struct ServiceInfo {
    google::protobuf::Service *service_;
    std::unordered_map<std::string, const google::protobuf::MethodDescriptor *>
        method_map_;  // 键是RPC方法名，值是该RPC方法对应的描述符
  };
  // 存储注册成功的服务对象和其服务方法的所有信息
  // 键是RPC服务名，值是该RPC服务对应的ServiceInfo
  std::unordered_map<std::string, ServiceInfo> service_map_;
};
#endif