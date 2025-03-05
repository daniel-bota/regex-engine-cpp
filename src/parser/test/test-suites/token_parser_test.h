#ifndef _REGEX_PARSER_TOKEN_PARSER_TEST_H
#define _REGEX_PARSER_TOKEN_PARSER_TEST_H

#include "pch/pch.h"

#include <parser/token_parser.h>

namespace regex::parser
{
    class token_parser_test : public ::testing::Test
    {
    protected:
        static void SetUpTestSuite();
        static void TearDownTestSuite();
        static token_parser _parser;
    };
}

#endif // _REGEX_PARSER_TOKEN_PARSER_TEST_H