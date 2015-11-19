cmake_minimum_required(VERSION 3.3)
project(comparison_of_array_and_vector)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(comparison_of_array_and_vector ${SOURCE_FILES})