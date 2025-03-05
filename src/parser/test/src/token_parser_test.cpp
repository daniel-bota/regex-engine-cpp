#include "test-suites/token_parser_test.h"

#include <parser/character.h>
#include <parser/interface/i_node.h>
#include <parser/syntax_tree.h>

NAMESPACE_BEGIN(regex::parser)


token_parser token_parser_test::_parser;


void token_parser_test::SetUpTestSuite()
{
}


void token_parser_test::TearDownTestSuite()
{
}


TEST_F(token_parser_test, computes_single_character)
{
    parse_result result = _parser.compute("a");
    character expected_token("a");
    ASSERT_EQ(parse_status::success, result.status);
    ASSERT_EQ(std::string(), result.message);
    ASSERT_TRUE(_parser.get_token());
    EXPECT_EQ(expected_token, *_parser.get_token());
}


NAMESPACE_END(regex::parser)