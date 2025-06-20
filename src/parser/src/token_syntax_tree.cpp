#include "parser/binary_token_node.h"
#include "parser/exception/invalid_argument.h"
#include "parser/interface/i_token.h"
#include "parser/token_syntax_tree.h"

#include <numeric>
#include <stack>


NAMESPACE_BEGIN(regex::parser)


// i_binary_token_node* const token_syntax_tree::root() const
// {
//     return _root.get();
// }


void token_syntax_tree::set_root(std::unique_ptr<i_binary_token_node> node)
{
    _root = std::move(node);
}


std::unique_ptr<i_binary_token_node>
    token_syntax_tree::create_node(std::unique_ptr<i_token> token) const
{
    if (!token)
        throw exception::invalid_argument(
            "The i_token passed as an argument to "
            "regex::parser::token_syntax_tree::create_node() "
            "cannot be null.");

    return std::make_unique<binary_token_node>(std::move(token));
}


std::unique_ptr<i_binary_token_node>
    regex::parser::token_syntax_tree::create_node(
        const i_token* const token) const
{
    if (!token)
        throw exception::invalid_argument(
            "The i_token passed as an argument to "
            "regex::parser::token_syntax_tree::create_node() "
            "cannot be null.");

    return std::make_unique<binary_token_node>(token->clone());
}


std::unique_ptr<i_binary_token_node>
    token_syntax_tree::create_node(const i_token& token) const
{
    return std::make_unique<binary_token_node>(token.clone());
}


std::string token_syntax_tree::print_token_sources(const tree_traversal& traversal) const
{
    switch (traversal) {
    case tree_traversal::dfs_post_order: {
        std::vector<std::string> tokens = get_token_sources_dfs_post_order();
        return std::accumulate(tokens.begin(), tokens.end(), std::string());
    }
    default:
        throw exception::invalid_argument("An unknown tree traversal type was "
                                          "provided for printing the syntax tree token sources.");
    }
}


std::vector<std::string>
    token_syntax_tree::get_token_source_list(const tree_traversal& traversal) const
{
    switch (traversal) {
    case tree_traversal::dfs_post_order:
        return get_token_sources_dfs_post_order();
    default:
        throw exception::invalid_argument(
            "An unknown tree traversal type was "
            "provided to get the syntax tree token sources.");
    }
}


std::vector<const i_token*> token_syntax_tree::get_token_list(
    const tree_traversal&) const
{
}


std::vector<std::string>
    token_syntax_tree::get_token_sources_dfs_post_order() const
{
    std::vector<std::string> result{};
    std::stack<i_binary_token_node*> stack;
    i_binary_token_node* current = _root.get();
    while (true) {
        while (current) {
            stack.push(current);
            stack.push(current);
            current = current->left();
        }
        if (stack.empty())
            return result;

        current = stack.top();
        stack.pop();
        if (!stack.empty() && stack.top() == current) {
            current = current->right();
        }
        else {
            result.push_back(current->get_token().get_source());
            current = nullptr;
        }
    }

    return result;
}


NAMESPACE_END(regex::parser)