add_executable(test_rpcconfig test_rpcconfig.cc)
add_executable(test_logger test_logger.cc)

target_link_libraries(test_logger myrpc)
target_link_libraries(test_rpcconfig myrpc)