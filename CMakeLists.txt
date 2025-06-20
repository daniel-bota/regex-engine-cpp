cmake_minimum_required(VERSION 3.30)

project(regex-engine-cpp)

set(CMAKE_CXX_STANDARD 23) # Enable the C++23 standard

# file(GLOB_RECURSE SOURCE_FILES src/*.cpp src/*.hpp)

include(src/testing-config.cmake)

add_subdirectory(src)
add_executable(regex-engine-cpp src/main.cpp)
# target_link_libraries(regex-engine-cpp PRIVATE framework)
# target_link_libraries(regex-engine-cpp PRIVATE parser)
# target_link_libraries(regex-engine-cpp PRIVATE pattern)
target_link_libraries(regex-engine-cpp PRIVATE compiler)
