#include <iostream>

#include "rpc_application.h"
#include "rpc_channel.h"
#include "user.pb.h"
using namespace std;
void CallLogin() {
  string name, pwd;
  cout << "---------- 登录 ----------" << endl;
  cout << "请输入名字:" << endl;
  cin >> name;
  cout << "请输入密码:" << endl;
  cin >> pwd;

  // 演示调用远程发布的rpc方法Login
  myrpc::UserServiceRpc_Stub stub(new RpcChannel());
  // rpc方法的请求参数
  myrpc::LoginRequest request;
  request.set_name(name);
  request.set_pwd(pwd);
  // rpc方法的响应
  myrpc::LoginResponse response;
  // 发起rpc方法的调用  同步的rpc调用过程  RpcChannel::callmethod
  stub.Login(nullptr, &request, &response,
             nullptr);  // RpcChannel->RpcChannel::callMethod
                        // 集中来做所有rpc方法调用的参数序列化和网络发送

  // 一次rpc调用完成，读调用的结果
  if (0 == response.result().errcode()) {
    std::cout << "rpc login response success:" << response.sucess()
              << std::endl;
  } else {
    std::cout << "rpc login response error : " << response.result().errmsg()
              << std::endl;
  }
}
void CallRegister() {
  string name, pwd;
  cout << "---------- 注册 ----------" << endl;
  cout << "请输入名字:" << endl;
  cin >> name;
  cout << "请输入密码:" << endl;
  cin >> pwd;

  // 演示调用远程发布的rpc方法Register
  myrpc::RegisterRequest req;
  req.set_id(2000);
  req.set_name(name);
  req.set_pwd(pwd);
  myrpc::RegisterResponse rsp;

  // 演示调用远程发布的rpc方法Login
  myrpc::UserServiceRpc_Stub stub(new RpcChannel());
  // 以同步的方式发起rpc调用请求，等待返回结果
  stub.Register(nullptr, &req, &rsp, nullptr);

  // 一次rpc调用完成，读调用的结果
  if (0 == rsp.result().errcode()) {
    std::cout << "rpc register response success:" << rsp.sucess() << std::endl;
  } else {
    std::cout << "rpc register response error : " << rsp.result().errmsg()
              << std::endl;
  }
}

int main(int argc, char **argv) {
  // 整个程序启动以后，想使用myrpc框架来享受rpc服务调用，一定需要先调用框架的初始化函数（只初始化一次）
  RpcApplication::Init(argc, argv);
  CallRegister();
  CallLogin();
  return 0;
}