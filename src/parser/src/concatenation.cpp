#include "parser/concatenation.h"

#include "framework/macros.h"
#include "parser/interface/i_ast_parser.h"
#include "parser/interface/i_token.h"

NAMESPACE_BEGIN(regex::parser)


concatenation::concatenation(const concatenation& other)
    : i_token()
{
    _source = other._source;
}


concatenation::~concatenation()
{
}


token_type concatenation::get_type() const
{
    return token_type::concatenation;
}


// operator_type concatenation::get_operator_type() const
// {
//     return operator_type();
// }


const std::string& concatenation::get_source() const
{
    return _source;
}

operator_precedence
    concatenation::get_operator_precedence_over(const i_token& other) const
{
    return get_operator_precedence_over(other.get_type());
}

operator_precedence concatenation::get_operator_precedence_over(
    const token_type& other_type) const
{
    switch (other_type) {
    case token_type::concatenation:
        return operator_precedence::equal;
    case token_type::quantifier:
        return operator_precedence::lower;
    case token_type::alternative:
        return operator_precedence::higher;
    default:
        return operator_precedence::higher;
    }
}


std::unique_ptr<i_token> concatenation::clone() const
{
    return std::make_unique<concatenation>(*this);
}


void concatenation::add_to_ast_parser(i_ast_parser& parser) const
{
    return parser.add_concatenation();
}

void concatenation::apply_to_ast_parser(i_ast_parser& parser) const
{
    return parser.apply_concatenation_from_stack(*this);
}


bool concatenation::operator==(const i_token& other) const
{
    return this->get_type() == other.get_type();
}


bool concatenation::operator!=(const i_token& other) const
{
    return !(*this == other);
}


NAMESPACE_END(regex::parser)