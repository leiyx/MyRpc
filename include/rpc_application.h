/*
 * @Author: lei
 * @Description: rpc框架的基础类，负责框架的一些初始化操作
 * @FilePath: /MyRpc/include/rpc_application.h
 */
#ifndef RPC_APPLICATION_H
#define RPC_APPLICATION_H
#include "rpc_channel.h"
#include "rpc_config.h"
#include "rpc_controller.h"

class RpcApplication {
 public:
  static void Init(int argc, char** argv);
  static RpcApplication& GetInstance();
  static RpcConfig& GetConfig();

 private:
  static RpcConfig config_;

  RpcApplication() {}
  RpcApplication(const RpcApplication&) = delete;
  RpcApplication(RpcApplication&&) = delete;
};
#endif