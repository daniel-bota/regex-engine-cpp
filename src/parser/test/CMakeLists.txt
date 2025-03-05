if (NOT BUILD_TESTING)
    return()
endif()

file(GLOB_RECURSE PARSER_TEST_SOURCES src/*.cpp test-suites/*.h)

add_executable(parser-test
    ${PARSER_TEST_SOURCES}
)
target_precompile_headers(parser-test PRIVATE pch/pch.h)

if (CONFIGURE_GOOGLETEST_AUTOMATICALLY)
    target_link_libraries(
        parser-test
        PRIVATE GTest::gtest
        PRIVATE GTest::gtest_main
        PRIVATE GTest::gmock
        PRIVATE GTest::gmock_main
    )
endif()

target_link_libraries(
    parser-test
    PRIVATE parser
)

target_include_directories(
    parser-test
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE $<TARGET_PROPERTY:parser,INTERFACE_INCLUDE_DIRECTORIES>
)

# enable_testing()

gtest_add_tests(
    TARGET parser-test
)
# gtest_discover_tests(parser-test)
