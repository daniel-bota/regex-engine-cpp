#include "parser/node.h"

#include "parser/interface/i_token.h"

NAMESPACE_BEGIN(regex::parser)


node::node(std::unique_ptr<i_token> token)
    : _token(std::move(token))
{
}


i_node* node::left() const
{
    return _left.get();
}


i_node* node::right() const
{
    return _right.get();
}


i_token* node::get_token() const
{
    return _token.get();
}


bool node::is_leaf() const
{
    return _left == nullptr && _right == nullptr;
}

void node::set_left(std::unique_ptr<i_node> node)
{
    _left = std::move(node);
}

void node::set_right(std::unique_ptr<i_node> node)
{
    _right = std::move(node);
}


NAMESPACE_END(regex::parser)