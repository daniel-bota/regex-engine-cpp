set (PARSER_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set (PARSER_HEADER_DIR ${PARSER_INCLUDE_DIR}/parser)
set (PARSER_INTERFACE_DIR ${PARSER_INCLUDE_DIR}/parser/interface)
set (PARSER_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

file(GLOB_RECURSE PARSER_SOURCES ${PARSER_HEADER_DIR}/*.h ${PARSER_SOURCE_DIR}/*.cpp)

add_library(parser STATIC ${PARSER_SOURCES})
# set_target_properties(parser PROPERTIES LINKER_LANGUAGE CXX)
# target_include_directories(parser PRIVATE ${PARSER_HEADER_DIR} ${PARSER_INTERFACE_DIR})
target_include_directories(parser PRIVATE ${PARSER_INCLUDE_DIR})
target_include_directories(parser INTERFACE ${PARSER_INCLUDE_DIR})
target_link_libraries(parser PUBLIC framework)

add_subdirectory(test)
