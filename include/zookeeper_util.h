#ifndef ZOOKEEPER_UTIL_H
#define ZOOKEEPER_UTIL_H
#include <semaphore.h>
#include <zookeeper/zookeeper.h>

#include <string>

// 封装的zk客户端类
class ZkClient {
 public:
  ZkClient();
  ~ZkClient();
  // zkclient启动连接zkserver
  void Connect();
  // 在zkserver上根据指定的path创建znode节点
  void Create(const char *path, const char *data, int datalen, int state = 0);
  // 根据参数指定的znode节点路径，或者znode节点的值
  std::string GetData(const char *path);

 private:
  // zk的客户端句柄
  zhandle_t *zhandle_;
};
#endif