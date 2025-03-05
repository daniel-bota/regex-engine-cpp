#ifndef _REGEX_PARSER_BASIC_PARSER_TEST_H
#define _REGEX_PARSER_BASIC_PARSER_TEST_H

#include "pch/pch.h"

#include <parser/basic_parser.h>

namespace regex::parser
{
    class basic_parser_test : public ::testing::Test
    {
    protected:
        static void SetUpTestSuite();
        static void TearDownTestSuite();
        static basic_parser _parser;
    };
}

#endif // _REGEX_PARSER_BASIC_PARSER_TEST_H