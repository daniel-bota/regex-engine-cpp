add_subdirectory(pattern)
# add_subdirectory(parser)
# add_subdirectory(compiler)

target_link_libraries(regex-engine-cpp PRIVATE pattern)
target_link_libraries(regex-engine-cpp PRIVATE parser)
target_link_libraries(regex-engine-cpp PRIVATE compiler)