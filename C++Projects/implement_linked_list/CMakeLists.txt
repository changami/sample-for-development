cmake_minimum_required(VERSION 3.2)
project(implement_linked_list)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(implement_linked_list ${SOURCE_FILES} linked_list.h linked_list.cpp list_node.cpp)