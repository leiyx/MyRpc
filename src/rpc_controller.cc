#include "rpc_controller.h"

RpcController::RpcController() {
  failed_ = false;
  err_text_ = "";
}

void RpcController::Reset() {
  failed_ = false;
  err_text_ = "";
}

bool RpcController::Failed() const { return failed_; }

std::string RpcController::ErrorText() const { return err_text_; }

void RpcController::SetFailed(const std::string& reason) {
  failed_ = true;
  err_text_ = reason;
}

// 目前未实现具体的功能
void RpcController::StartCancel() {}
void RpcController::ConnectCancel() {}
bool RpcController::IsCanceled() const { return false; }
void RpcController::NotifyOnCancel(google::protobuf::Closure* callback) {}