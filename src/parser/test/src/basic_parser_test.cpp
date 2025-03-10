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


void basic_parser_test::test_expected_ast_traversal(
    const std::string& regex,
    const tree_traversal& traversal)
{
    ASSERT_NO_THROW(_parser.compute(regex));
    std::string ast_traversal;
    ASSERT_NO_THROW(ast_traversal = _parser.get_syntax_tree().print(traversal));
    EXPECT_EQ(regex, ast_traversal);
}


TEST_F(basic_parser_test, computes_single_character)
{
    test_expected_ast_traversal("a", tree_traversal::dfs_post_order);
}

TEST_F(basic_parser_test, computes_concatenation)
{
    test_expected_ast_traversal("ab", tree_traversal::dfs_post_order);
}

TEST_F(basic_parser_test, computes_kleene_closure)
{
    test_expected_ast_traversal("a*", tree_traversal::dfs_post_order);
    test_expected_ast_traversal("a*b", tree_traversal::dfs_post_order);
}


NAMESPACE_END(regex::parser)