#include "test-suites/basic_parser_test.h"

#include <parser/character.h>
#include <parser/lexer.h>
#include <parser/token_syntax_tree.h>

namespace
{
    const std::string concat_src{};
}

NAMESPACE_BEGIN(regex::parser)


basic_parser basic_parser_test::_parser(std::make_unique<lexer>());


void basic_parser_test::SetUpTestSuite()
{
}


void basic_parser_test::TearDownTestSuite()
{
}


void basic_parser_test::test_expected_ast_traversal(
    const std::string& regex,
    const tree_traversal& traversal,
    const std::vector<std::string>& expected_output)
{
    ASSERT_NO_THROW(_parser.compute(regex));
    std::vector<std::string> ast_traversal;
    ASSERT_NO_THROW(ast_traversal =
                        _parser.get_syntax_tree().print_node_list(traversal));
    EXPECT_EQ(expected_output, ast_traversal);
}


TEST_F(basic_parser_test, computes_single_character)
{
    test_expected_ast_traversal("a", tree_traversal::dfs_post_order, {"a"});
}

TEST_F(basic_parser_test, computes_concatenation)
{
    test_expected_ast_traversal(
        "abcd",
        tree_traversal::dfs_post_order,
        {"a", "b", concat_src, "c", concat_src, "d", concat_src});
}

TEST_F(basic_parser_test, computes_kleene_closure)
{
    test_expected_ast_traversal("a*",
                                tree_traversal::dfs_post_order,
                                {"a", "*"});
    test_expected_ast_traversal(
        "a*b*c",
        tree_traversal::dfs_post_order,
        {"a", "*", "b", "*", concat_src, "c", concat_src});
}


TEST_F(basic_parser_test, computes_alternative)
{
    test_expected_ast_traversal("a|b",
                                tree_traversal::dfs_post_order,
                                {"a", "b", "|"});
    test_expected_ast_traversal("ab*c|de",
                                tree_traversal::dfs_post_order,
                                {"a",
                                 "b",
                                 "*",
                                 concat_src,
                                 "c",
                                 concat_src,
                                 "d",
                                 "e",
                                 concat_src,
                                 "|"});
}


NAMESPACE_END(regex::parser)