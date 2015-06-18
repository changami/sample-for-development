cmake_minimum_required(VERSION 3.2)
project(detect_error_of_html_tags)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(detect_error_of_html_tags ${SOURCE_FILES})