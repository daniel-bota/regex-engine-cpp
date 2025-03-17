#include "test-suites/token_parser_test.h"

#include <parser/alternative.h>
#include <parser/character.h>
#include <parser/interface/i_node.h>
#include <parser/quantifier.h>
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
    ASSERT_NO_THROW(_parser.compute("a"));
    ASSERT_TRUE(_parser.get_token());
    character expected("a");
    EXPECT_EQ(expected, *_parser.get_token());
}

TEST_F(token_parser_test, computes_kleene_closure)
{
    ASSERT_NO_THROW(_parser.compute("*abc"));
    ASSERT_TRUE(_parser.get_token());
    quantifier expected("*", quantifier::range{0, -1});
    EXPECT_EQ(expected, *_parser.get_token());
}

TEST_F(token_parser_test, computes_alternative_token)
{
    ASSERT_NO_THROW(_parser.compute("|"));
    ASSERT_TRUE(_parser.get_token());
    alternative expected("|");
    EXPECT_EQ(expected, *_parser.get_token());
}


NAMESPACE_END(regex::parser)