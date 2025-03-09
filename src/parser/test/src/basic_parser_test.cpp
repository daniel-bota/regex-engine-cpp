#include "test-suites/basic_parser_test.h"

#include <parser/character.h>
#include <parser/interface/i_node.h>
#include <parser/syntax_tree.h>
#include <parser/token_parser.h>

namespace
{
    const regex::parser::parse_status status_success{
        regex::parser::parse_status::success};
    const regex::parser::parse_result result_success{status_success,
                                                     std::string()};
}

NAMESPACE_BEGIN(regex::parser)


basic_parser basic_parser_test::_parser(std::make_unique<token_parser>());


void basic_parser_test::SetUpTestSuite()
{
}


void basic_parser_test::TearDownTestSuite()
{
}


TEST_F(basic_parser_test, computes_single_character)
{
    ASSERT_NO_THROW(_parser.compute("a"));
    std::string traversal;
    ASSERT_NO_THROW(traversal = _parser.get_syntax_tree().print(
                        tree_traversal::dfs_post_order));
    EXPECT_EQ(std::string("a"), traversal);
}

TEST_F(basic_parser_test, computes_concatenation)
{
    ASSERT_NO_THROW(_parser.compute("ab"));
    std::string traversal;
    ASSERT_NO_THROW(traversal = _parser.get_syntax_tree().print(
                        tree_traversal::dfs_post_order));
    EXPECT_EQ(std::string("ab"), traversal);
}


NAMESPACE_END(regex::parser)