cmake_minimum_required(VERSION 3.24)
project(LCFS)

set(CMAKE_CXX_STANDARD 17)

add_executable(LCFS main.cpp Process.cpp Process.h generator.h fetchData.h)
