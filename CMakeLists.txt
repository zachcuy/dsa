cmake_minimum_required(VERSION 3.29)

# Project name and version
project(dsa VERSION 1.0.0 LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-Wall")

# Generate compile_commands.json for language servers
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add an executable
add_executable(dsa src/main.cpp)

# Include directories
target_include_directories(dsa PRIVATE include include/dump)
