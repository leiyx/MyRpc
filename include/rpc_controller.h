#ifndef RPC_CONTROLLER_H
#define RPC_CONTROLLER_H
#include <google/protobuf/service.h>

#include <string>

class RpcController : public google::protobuf::RpcController {
 public:
  RpcController();
  void Reset();
  bool Failed() const;
  std::string ErrorText() const;
  void SetFailed(const std::string& reason);

  // 目前未实现具体的功能
  void StartCancel();
  void ConnectCancel();
  bool IsCanceled() const;
  void NotifyOnCancel(google::protobuf::Closure* callback);

 private:
  bool failed_;           // RPC方法执行过程中的状态
  std::string err_text_;  // RPC方法执行过程中的错误信息
};
#endif