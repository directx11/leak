cmake_minimum_required(VERSION 3.10)

include(ExternalProject)

project(grpc_test)

# set(CMAKE_EXT_BUILD ext)
# set(CMAKE_EXT_GRPC_BUILD ${CMAKE_EXT_BUILD}/grpc)
# file(MAKE_DIRECTORY ${CMAKE_EXT_GRPC_BUILD})

# ExternalProject_Add(grpc
#         PREFIX grpc
#         GIT_REPOSITORY "https://github.com/grpc/grpc.git"
#         GIT_TAG "v1.53.0"
#         CMAKE_ARGS
#         -DCMAKE_INSTALL_PREFIX=./../../../${CMAKE_EXT_GRPC_BUILD}
#         -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
#         -DgRPC_BUILD_TESTS=OFF
#         -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
# )

include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_EXT_GRPC_BUILD}/include)
link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_EXT_GRPC_BUILD}/lib)

add_executable(${PROJECT_NAME} main.cpp service.pb.cc service.grpc.pb.cc)
target_link_libraries(${PROJECT_NAME}
    protobuf
    gpr
    grpc
    grpc++
    grpc++_reflection
    grpc_unsecure
    grpc++_unsecure)