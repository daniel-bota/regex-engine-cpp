#include "parser/binary_token_node.h"
#include "parser/exception/invalid_argument.h"
#include "parser/interface/i_token.h"

NAMESPACE_BEGIN(regex::parser)


binary_token_node::binary_token_node(std::unique_ptr<i_token> token)
    : _token(std::move(token))
{
    if (!_token)
        throw exception::invalid_argument(
            "The i_token passed as argument to the constructor of "
            "regex::parser::node cannot be null.");
    token = nullptr;
}

binary_token_node::binary_token_node(const i_token* const token)
    : _token(token->clone())
{
    if (!_token)
        throw exception::invalid_argument(
            "The i_token passed as argument to the constructor of "
            "regex::parser::node cannot be null.");
}

binary_token_node::binary_token_node(const i_token& token)
    : _token(token.clone())
{
}


i_binary_token_node* binary_token_node::left() const
{
    return _left.get();
}


i_binary_token_node* binary_token_node::right() const
{
    return _right.get();
}


const i_token& binary_token_node::get_token() const
{
    return *_token;
}


bool binary_token_node::is_leaf() const
{
    return _left == nullptr && _right == nullptr;
}

void binary_token_node::set_left(std::unique_ptr<i_binary_token_node> node)
{
    _left = std::move(node);
}

void binary_token_node::set_right(std::unique_ptr<i_binary_token_node> node)
{
    _right = std::move(node);
}


NAMESPACE_END(regex::parser)