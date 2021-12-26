/*
 * @Author: lei
 * @Description:
 * 所有通过stub代理对象调用的rpc方法，统一做rpc方法调用的数据数据序列化和网络发送
 * @FilePath: /MyRpc/include/rpc_channel.h
 */
#ifndef RPC_CHANNEL_H
#define RPC_CHANNEL_H
#include <google/protobuf/descriptor.h>
#include <google/protobuf/message.h>
#include <google/protobuf/service.h>

class RpcChannel : public google::protobuf::RpcChannel {
 public:
  void CallMethod(const google::protobuf::MethodDescriptor* method,
                  google::protobuf::RpcController* controller,
                  const google::protobuf::Message* request,
                  google::protobuf::Message* response,
                  google::protobuf::Closure* done);
};
#endif