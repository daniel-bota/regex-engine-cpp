#include "parser/node.h"

#include "parser/exception/invalid_argument.h"
#include "parser/interface/i_token.h"

NAMESPACE_BEGIN(regex::parser)


node::node(std::unique_ptr<i_token> token)
    : _token(std::move(token))
{
    if (!_token)
        throw exception::invalid_argument(
            "The i_token passed as argument to the constructor of "
            "regex::parser::node cannot be null.");
    token = nullptr;
}

node::node(const i_token* const token)
    : _token(token->clone())
{
    if (!_token)
        throw exception::invalid_argument(
            "The i_token passed as argument to the constructor of "
            "regex::parser::node cannot be null.");
}

node::node(const i_token& token)
    : _token(token.clone())
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


const i_token& node::get_token() const
{
    return *_token;
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