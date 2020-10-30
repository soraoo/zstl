cmake_minimum_required(VERSION 3.17)
project(zstl)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(zstl main.cpp include/construct.hpp include/util.hpp)