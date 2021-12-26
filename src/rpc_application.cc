#include "rpc_application.h"

#include <unistd.h>

#include <iostream>
#include <string>

#include "logger.h"

RpcConfig RpcApplication::config_;

void ShowArgsHelp() {
  std::cout << "format: command -i <configfile>" << std::endl;
  LOG_FATAL("Please retry!format: command -i <configfile>");
}

void RpcApplication::Init(int argc, char** argv) {
  LOG_INIT("./log", LoggerLevel::INFO);
  LOG_INFO("log_file path:%s,loglevel:%d","./log",LoggerLevel::INFO);
  if (argc < 2) {
    ShowArgsHelp();
    exit(EXIT_FAILURE);
  }
  int c = 0;
  std::string config_file;
  while ((c = getopt(argc, argv, "i:")) != -1) {
    switch (c) {
      case 'i':
        config_file = optarg;
        break;
      case '?':
        ShowArgsHelp();
        exit(EXIT_FAILURE);
      case ':':
        ShowArgsHelp();
        exit(EXIT_FAILURE);
      default:
        break;
    }
  }
  config_.LoadConfigFile(config_file.c_str());
}

RpcApplication& RpcApplication::GetInstance() {
  static RpcApplication app;
  return app;
}

RpcConfig& RpcApplication::GetConfig() { return config_; }