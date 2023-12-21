cmake_minimum_required(VERSION 3.10)

include(ExternalProject)
include(FetchContent)

project(grpc_test)

set(CMAKE_EXT ext)
set(CMAKE_EXT_GRPC ${CMAKE_EXT}/grpc)
set(CMAKE_EXT_GRPC_BIN ${CMAKE_EXT_GRPC}/bin)
set(FETCHCONTENT_QUIET OFF)

set(CMAKE_PREFIX_PATH ${CMAKE_EXT_GRPC})
find_package(protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)
find_package(Threads)

execute_process(COMMAND pwd)
execute_process(COMMAND ${CMAKE_EXT_GRPC_BIN}/protoc --cpp_out=. --proto_path ../protos service.proto)
execute_process(COMMAND ${CMAKE_EXT_GRPC_BIN}/protoc --grpc_out=. --plugin=protoc-gen-grpc=${CMAKE_EXT_GRPC_BIN}/grpc_cpp_plugin --proto_path ../protos service.proto)

add_executable(${PROJECT_NAME} main.cpp service.pb.cc service.grpc.pb.cc)
target_link_libraries(${PROJECT_NAME} PRIVATE
    protobuf::libprotobuf
	gRPC::grpc
	gRPC::grpc++
	gRPC::grpc++_reflection)