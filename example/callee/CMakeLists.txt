set(SRC_LIST1 userservice.cc ../user.pb.cc)
set(SRC_LIST2 friendservice.cc ../friend.pb.cc)

add_executable(user_service_provider ${SRC_LIST1})
add_executable(friend_service_provider ${SRC_LIST2})
target_link_libraries(user_service_provider myrpc protobuf)
target_link_libraries(friend_service_provider myrpc protobuf)