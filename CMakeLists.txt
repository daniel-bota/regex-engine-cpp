cmake_minimum_required(VERSION 3.30)

project(regex-engine-cpp)

set(CMAKE_CXX_STANDARD 23) # Enable the C++23 standard

# file(GLOB_RECURSE SOURCE_FILES src/*.cpp src/*.hpp)

add_executable(regex-engine-cpp src/main.cpp)
add_subdirectory(src)
