#include "parser/character.h"

#include "parser/interface/i_ast_parser.h"
#include "parser/interface/i_quantifier.h"

NAMESPACE_BEGIN(regex::parser)


character::character(const std::string& source)
{
    _source = source.front();
    // _quantifier = nullptr;
}


// character::character(const std::string& source, const i_quantifier&
// quantifier)
// {
//     _source = source.front();
//     _quantifier = quantifier.clone();
// }


character::character(const character& other)
    : i_token()
{
    _source = other._source;
    // _quantifier = other._quantifier;
}


token_type character::get_type() const
{
    return token_type::character;
}


// operator_type character::get_operator_type() const
// {
//     return operator_type::none;
// }


// const quantifier& regex::parser::character::get_quantifier() const
// {
//     return _quantifier;
// }


const std::string& character::get_source() const
{
    return _source;
}

operator_precedence
    character::get_operator_precedence_over(const i_token& other) const
{
    return get_operator_precedence_over(other.get_type());
}

operator_precedence character::get_operator_precedence_over(const token_type&) const
{
    return operator_precedence::none;
}


std::unique_ptr<i_token> character::clone() const
{
    return std::make_unique<character>(*this);
}


void character::add_to_ast_parser(i_ast_parser& parser) const
{
    parser.add_character(*this);
}

void character::apply_to_ast_parser(i_ast_parser&) const
{
    return;
}


bool character::operator==(const i_token& other) const
{
    return this->get_type() == other.get_type()
           && this->_source == other.get_source();
}


bool character::operator!=(const i_token& other) const
{
    return !(*this == other);
}


NAMESPACE_END(regex::parser)