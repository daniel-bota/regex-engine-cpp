set (PATTERN_INTERFACE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/interface)
set (PATTERN_HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set (PATTERN_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set (PATTERN_INTERFACES
    ${PATTERN_INTERFACE_DIR}/imatch_result.h
    ${PATTERN_INTERFACE_DIR}/interface.h
    ${PATTERN_INTERFACE_DIR}/ipattern_parser.h
    ${PATTERN_INTERFACE_DIR}/ipattern.h
    ${PATTERN_INTERFACE_DIR}/isequence.h
)

set (PATTERN_HEADERS 
    ${PATTERN_HEADER_DIR}/alpha.h
    ${PATTERN_HEADER_DIR}/character_group.h
    ${PATTERN_HEADER_DIR}/character.h
    ${PATTERN_HEADER_DIR}/choice.h
    ${PATTERN_HEADER_DIR}/digit.h
    ${PATTERN_HEADER_DIR}/match_result.h
    ${PATTERN_HEADER_DIR}/one_or_more.h
    ${PATTERN_HEADER_DIR}/optional.h
    ${PATTERN_HEADER_DIR}/pattern_parser.h
    ${PATTERN_HEADER_DIR}/regex.h
    ${PATTERN_HEADER_DIR}/sequence.h
    ${PATTERN_HEADER_DIR}/text.h
    ${PATTERN_HEADER_DIR}/wildcard.h
)

set (PATTERN_IMPLEMENTATION
    ${PATTERN_SOURCE_DIR}/alpha.cpp
    ${PATTERN_SOURCE_DIR}/character_group.cpp
    ${PATTERN_SOURCE_DIR}/character.cpp
    ${PATTERN_SOURCE_DIR}/choice.cpp
    ${PATTERN_SOURCE_DIR}/digit.cpp
    ${PATTERN_SOURCE_DIR}/match_result.cpp
    ${PATTERN_SOURCE_DIR}/one_or_more.cpp
    ${PATTERN_SOURCE_DIR}/optional.cpp
    ${PATTERN_SOURCE_DIR}/pattern_parser.cpp
    ${PATTERN_SOURCE_DIR}/regex.cpp
    ${PATTERN_SOURCE_DIR}/sequence.cpp
    ${PATTERN_SOURCE_DIR}/text.cpp
    ${PATTERN_SOURCE_DIR}/wildcard.cpp
)

set (PATTERN_SOURCES ${PATTERN_INTERFACES} ${PATTERN_HEADERS} ${PATTERN_IMPLEMENTATION})

add_library(pattern STATIC ${PATTERN_SOURCES})

target_include_directories(pattern INTERFACE ${PATTERN_INTERFACE_DIR} ${PATTERN_HEADER_DIR})
