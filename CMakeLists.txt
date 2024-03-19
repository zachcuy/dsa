cmake_minimum_required(VERSION 3.27)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(headers)
include_directories(headers/cpp-dump)

project(
  dsa
  VERSION 0.0.1
  LANGUAGES CXX)

set(SRC main.cpp leetcode/621.task-scheduler.cpp)

add_executable(dsa ${SRC})
