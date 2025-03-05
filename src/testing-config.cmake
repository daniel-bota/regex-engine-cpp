include(CTest)
include(GoogleTest)

if(NOT BUILD_TESTING)
    return()
endif()

set(
    CONFIGURE_GOOGLETEST_AUTOMATICALLY
    ON
    CACHE
    BOOL
    "Automatically find and configure Google Test
    . You will need to reconfigure the project using a package manager toolchain file for this to work."
)

if (CONFIGURE_GOOGLETEST_AUTOMATICALLY)
    find_package(GTest CONFIG REQUIRED)
endif()
