set (COMPILER_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set (COMPILER_HEADER_DIR ${COMPILER_INCLUDE_DIR}/compiler)
set (COMPILER_INTERFACE_DIR ${COMPILER_INCLUDE_DIR}/compiler/interface)
set (COMPILER_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

file(GLOB_RECURSE COMPILER_SOURCES ${COMPILER_HEADER_DIR}/*.h ${COMPILER_SOURCE_DIR}/*.cpp)

add_library(compiler STATIC ${COMPILER_SOURCES})

target_include_directories(compiler PRIVATE ${COMPILER_INCLUDE_DIR})
target_include_directories(compiler INTERFACE ${COMPILER_INCLUDE_DIR})
# target_link_libraries(compiler PRIVATE framework)
target_link_libraries(compiler PRIVATE parser)

add_subdirectory(test)