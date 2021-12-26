#include "zookeeper_util.h"

#include <semaphore.h>

#include <iostream>

#include "logger.h"
#include "rpc_application.h"

// 全局的watcher观察器   zkserver给zkclient的通知
void global_watcher(zhandle_t *zh, int type, int state, const char *path,
                    void *watcherCtx) {
  if (type == ZOO_SESSION_EVENT)  // 回调的消息类型是和会话相关的消息类型
  {
    if (state == ZOO_CONNECTED_STATE)  // zkclient和zkserver连接成功
    {
      sem_t *sem = (sem_t *)zoo_get_context(zh);
      sem_post(sem);
    }
  }
}

ZkClient::ZkClient() : zhandle_(nullptr) {}

ZkClient::~ZkClient() {
  if (zhandle_ != nullptr) {
    zookeeper_close(zhandle_);  // 关闭句柄，释放资源.类似于MySQL_Conn
  }
}

// 连接zkserver
void ZkClient::Connect() {
  std::string host =
      RpcApplication::GetInstance().GetConfig().GetConfigOpt("zookeeperip");
  std::string port =
      RpcApplication::GetInstance().GetConfig().GetConfigOpt("zookeeperport");
  std::string connstr = host + ":" + port;
  LOG_INFO("zookeeper server ip:port is:%s", connstr.c_str());

  /*
  zookeeper_mt：多线程版本
  zookeeper的API客户端程序提供了三个线程
  API调用线程
  网络I/O线程  pthread_create  poll
  watcher回调线程 pthread_create
  */
  zhandle_ = zookeeper_init(connstr.c_str(), global_watcher, 30000, nullptr,
                            nullptr, 0);
  if (nullptr == zhandle_) {
    LOG_ERROR("zookeeper_init error!");
    exit(EXIT_FAILURE);
  }

  sem_t sem;
  sem_init(&sem, 0, 0);
  zoo_set_context(zhandle_, &sem);

  sem_wait(&sem);
  LOG_INFO("zookeeper_init success!");
}

void ZkClient::Create(const char *path, const char *data, int datalen,
                      int state) {
  char path_buffer[128];
  int bufferlen = sizeof(path_buffer);
  int flag;
  // 先判断path表示的znode节点是否存在，如果存在，就不再重复创建了
  flag = zoo_exists(zhandle_, path, 0, nullptr);
  if (ZNONODE == flag)  // 表示path的znode节点不存在
  {
    // 创建指定path的znode节点了
    flag = zoo_create(zhandle_, path, data, datalen, &ZOO_OPEN_ACL_UNSAFE,
                      state, path_buffer, bufferlen);
    if (flag == ZOK) {
      LOG_INFO("znode create success... path:%s", path);
    } else {
      LOG_ERROR("flag:%d", flag);
      LOG_FATAL("znode create error... path:%s", path);
    }
  }
}

// 根据指定的path，获取znode节点的值
std::string ZkClient::GetData(const char *path) {
  char buffer[64];
  int bufferlen = sizeof(buffer);
  int flag = zoo_get(zhandle_, path, 0, buffer, &bufferlen, nullptr);
  if (flag != ZOK) {
    LOG_ERROR("get znode error... path:%s", path);
    return "";
  } else {
    return buffer;
  }
}