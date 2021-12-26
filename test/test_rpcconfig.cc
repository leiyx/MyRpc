#include <iostream>

#include "rpc_config.h"
int main() {
  RpcConfig rpc_config;
  rpc_config.LoadConfigFile("rpc.conf");
  std::cout << "rpcserverip:" << rpc_config.GetConfigOpt("rpcserverip")
            << std::endl;
  std::cout << "rpcserverport:" << rpc_config.GetConfigOpt("rpcserverport")
            << std::endl;
  std::cout << "zookeeperip:" << rpc_config.GetConfigOpt("zookeeperip")
            << std::endl;
  std::cout << "zookeeperport:" << rpc_config.GetConfigOpt("zookeeperport")
            << std::endl;
  return 0;
}