#include "parser/alternative.h"

#include "framework/macros.h"
#include "parser/interface/i_ast_parser.h"

NAMESPACE_BEGIN(regex::parser)


alternative::alternative(const std::string& source)
    : _source(source)
{
}

alternative::alternative(const alternative& other)
{
    _source = other._source;
}


token_type alternative::get_type() const
{
    return token_type::alternative;
}


const std::string& alternative::get_source() const
{
    return _source;
}


operator_precedence
    alternative::get_operator_precedence_over(const i_token& token) const
{
    return get_operator_precedence_over(token.get_type());
}


operator_precedence
    alternative::get_operator_precedence_over(const token_type& type) const
{
    switch (type) {
    case token_type::alternative:
        return operator_precedence::equal;
    case token_type::quantifier:
    case token_type::concatenation:
        return operator_precedence::lower;
    default:
        return operator_precedence::higher;
    }
}


std::unique_ptr<i_token> alternative::clone() const
{
    return std::make_unique<alternative>(*this);
}


void alternative::add_to_ast_parser(i_ast_parser& parser) const
{
    parser.add_alternative(*this);
}


void alternative::apply_to_ast_parser(i_ast_parser& parser) const
{
    parser.apply_alternative_from_stack(*this);
}


bool alternative::operator==(const i_token& other) const
{
    return this->get_type() == other.get_type()
    && this->_source == other.get_source();
}


bool alternative::operator!=(const i_token& other) const
{
    return !(*this == other);
}


NAMESPACE_END(regex::parser)