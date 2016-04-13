cmake_minimum_required(VERSION 3.3)
project(hihocode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES 1044.cpp)
add_executable(1044 ${SOURCE_FILES})