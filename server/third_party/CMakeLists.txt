cmake_minimum_required(VERSION 3.10)

include(ExternalProject)

project(grpc_test)

set(CMAKE_EXT ext)
set(CMAKE_EXT_GRPC ${CMAKE_EXT}/grpc)
set(CMAKE_EXT_GRPC_BIN ${CMAKE_EXT_GRPC}/bin)

ExternalProject_Add(grpc
      PREFIX grpc
      GIT_REPOSITORY "https://github.com/grpc/grpc.git"
      GIT_TAG "v1.53.0"
      CMAKE_ARGS
      -DCMAKE_INSTALL_PREFIX=./../../../../${CMAKE_EXT_GRPC}
      -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
      -DgRPC_BUILD_TESTS=OFF
      -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
)