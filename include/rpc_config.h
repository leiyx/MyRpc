/*
 * @Author: lei
 * @Description: 框架读取配置文件类
 * @FilePath: /MyRpc/include/rpc_config.h
 */
#ifndef RPC_CONFIG_H
#define RPC_CONFIG_H
#include <string>
#include <unordered_map>

// 配置文件中的配置选项有：rpcserverip、rpcserverport、zookeeperip、zookeeperport
class RpcConfig {
 public:
  // 负责解析加载配置文件
  void LoadConfigFile(const char *config_file);
  // 查询配置项信息
  std::string GetConfigOpt(const std::string &key);

 private:
  std::unordered_map<std::string, std::string> config_map_;
  // 去掉字符串前后的空格
  void Trim(std::string &src_buf);
};
#endif