if (NOT BUILD_TESTING)
    return()
endif()

file(GLOB_RECURSE COMPILER_TEST_SOURCES src/*.cpp test-suites/*.h)

add_executable(compiler-test
    ${COMPILER_TEST_SOURCES}
)
target_precompile_headers(compiler-test PRIVATE pch/pch.h)

if (CONFIGURE_GOOGLETEST_AUTOMATICALLY)
    target_link_libraries(
        compiler-test
        PRIVATE GTest::gtest
        PRIVATE GTest::gtest_main
        PRIVATE GTest::gmock
        PRIVATE GTest::gmock_main
    )
endif()

target_link_libraries(
    compiler-test
    PRIVATE parser
)

target_include_directories(
    compiler-test
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE $<TARGET_PROPERTY:parser,INTERFACE_INCLUDE_DIRECTORIES>
)

gtest_add_tests(
    TARGET compiler-test
)