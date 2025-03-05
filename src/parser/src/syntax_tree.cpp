#include "parser/syntax_tree.h"

#include <parser/interface/i_token.h>
#include <parser/node.h>
#include <stack>


NAMESPACE_BEGIN(regex::parser)


i_node* syntax_tree::root() const
{
    return _root.get();
}


void syntax_tree::set_root(std::unique_ptr<i_node> node)
{
    _root = std::move(node);
}


std::unique_ptr<i_node>
    syntax_tree::create_node(std::unique_ptr<i_token> token) const
{
    return std::make_unique<node>(std::move(token));
}


std::unique_ptr<i_node>
    syntax_tree::create_node(const i_token* const token) const
{
    return std::make_unique<node>(token->clone());
}


std::string syntax_tree::print(const tree_traversal& traversal) const
{
    switch (traversal) {
    case tree_traversal::dfs_post_order:
        return print_dfs_post_order();
    default:
        return std::string();
    }
}


std::string syntax_tree::print_dfs_post_order() const
{
    std::string result{""};
    std::stack<i_node*> stack;
    i_node* current = _root.get();
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
            result += current->get_token()->get_source();
            current = nullptr;
        }
    }

    return result;
}


NAMESPACE_END(regex::parser)