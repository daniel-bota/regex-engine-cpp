#include "test-suites/basic_parser_test.h"

#include <parser/character.h>
#include <parser/interface/i_node.h>
#include <parser/syntax_tree.h>
#include <parser/token_parser.h>

namespace
{
    const regex::parser::parse_status status_success{
        regex::parser::parse_status::success};
    const regex::parser::parse_result result_success{
        status_success,
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
    parse_result result = _parser.compute("a");
    std::string expected_traversal("a");
    ASSERT_EQ(status_success, result.status);
    EXPECT_EQ(expected_traversal,
              _parser.get_syntax_tree()->print(tree_traversal::dfs_post_order));
}

TEST_F(basic_parser_test, computes_concatenation)
{
    parse_result result = _parser.compute("ab");
    std::string expected_traversal("ab");
    ASSERT_EQ(status_success, result.status);
    EXPECT_EQ(expected_traversal,
              _parser.get_syntax_tree()->print(tree_traversal::dfs_post_order));

}


NAMESPACE_END(regex::parser)