cmake_minimum_required(VERSION 3.30)

project(regex-engine-test)

set(CMAKE_CXX_STANDARD 23) # Enable the C++23 standard

# file(GLOB_RECURSE SOURCE_FILES src/*.cpp src/*.hpp)

find_library(GTEST gtest $ENV{GTEST_1.15.2}/lib)
find_library(GMOCK gmock $ENV{GTEST_1.15.2}/lib)
find_library(GTEST_MAIN gtest_main $ENV{GTEST_1.15.2}/lib/manual-link)
find_library(GMOCK_MAIN gmock_main $ENV{GTEST_1.15.2}/lib/manual-link)

add_executable(regex-engine-test src/pch.cpp)

target_include_directories(regex-engine-test PRIVATE $ENV{GTEST_1.15.2}/include)
target_include_directories(regex-engine-test PRIVATE src)
target_link_libraries(regex-engine-test PRIVATE ${GTEST})
target_link_libraries(regex-engine-test PRIVATE ${GTEST_MAIN})
target_link_libraries(regex-engine-test PRIVATE ${GMOCK})
target_link_libraries(regex-engine-test PRIVATE ${GMOCK_MAIN})

add_subdirectory(src)
