cmake_minimum_required(VERSION 3.2)
project(implement_binary_tree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(implement_binary_tree ${SOURCE_FILES} Node.cpp BinaryTree.cpp BinaryTree.h)