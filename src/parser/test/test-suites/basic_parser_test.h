#ifndef _REGEX_PARSER_BASIC_PARSER_TEST_H
#define _REGEX_PARSER_BASIC_PARSER_TEST_H

#include "pch/pch.h"

#include <parser/basic_parser.h>

namespace regex::parser
{
    enum class tree_traversal;
}

namespace regex::parser
{
    class basic_parser_test : public ::testing::Test
    {
    protected:
        static void SetUpTestSuite();
        static void TearDownTestSuite();
        static basic_parser _parser;

        void test_expected_ast_traversal(
            const std::string& regex,
            const tree_traversal& traversal,
            const std::vector<std::string>& expected_output);
    };
}

#endif // _REGEX_PARSER_BASIC_PARSER_TEST_H