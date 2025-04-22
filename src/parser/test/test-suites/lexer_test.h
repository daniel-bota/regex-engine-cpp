#ifndef _REGEX_PARSER_LEXER_TEST_H
#define _REGEX_PARSER_LEXER_TEST_H

#include "pch/pch.h"

#include <parser/lexer.h>

namespace regex::parser
{
    class lexer_test : public ::testing::Test
    {
    protected:
        static void SetUpTestSuite();
        static void TearDownTestSuite();
        static lexer _parser;
    };
}

#endif // _REGEX_PARSER_LEXER_TEST_H