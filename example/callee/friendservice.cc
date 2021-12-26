#include <iostream>
#include <string>
#include <vector>

#include "friend.pb.h"
#include "logger.h"
#include "rpc_application.h"
#include "rpc_server.h"

class FriendService : public myrpc::FiendServiceRpc {
 public:
  std::vector<std::string> GetFriendsList(uint32_t userid) {
    LOG_INFO("do GetFriendsList service! userid:%d", userid);
    std::vector<std::string> vec;
    vec.push_back("gao yang");
    vec.push_back("liu hong");
    vec.push_back("wang shuo");
    return vec;
  }

  // 重写基类方法
  void GetFriendsList(::google::protobuf::RpcController* controller,
                      const ::myrpc::GetFriendsListRequest* request,
                      ::myrpc::GetFriendsListResponse* response,
                      ::google::protobuf::Closure* done) {
    uint32_t userid = request->userid();
    std::vector<std::string> friendsList = GetFriendsList(userid);
    response->mutable_result()->set_errcode(0);
    response->mutable_result()->set_errmsg("");
    for (std::string& name : friendsList) {
      std::string* p = response->add_friends();
      *p = name;
    }
    done->Run();
  }
};

int main(int argc, char** argv) {
  // 调用框架的初始化操作
  RpcApplication::Init(argc, argv);

  // server是一个rpc网络服务对象。把UserService对象发布到rpc节点上
  RpcServer server;
  server.NotifyService(new FriendService());

  // 启动一个rpc服务发布节点   Run以后，进程进入阻塞状态，等待远程的rpc调用请求
  server.Run(1);

  return 0;
}