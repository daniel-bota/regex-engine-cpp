#include "parser/quantifier.h"

#include "parser/exception/invalid_argument.h"
#include "parser/interface/i_ast_parser.h"

#include <type_traits>

NAMESPACE_BEGIN(regex::parser)


quantifier::range::range(const unsigned short& min, const int& max)
    : _min(min),
      _max(max)
{
}


unsigned short quantifier::range::min() const
{
    return _min;
}


int quantifier::range::max() const
{
    return _max;
}


quantifier::quantifier(const std::string& source, const range& range)
    : _source(source),
      _range(range)
{
    if (_range.max() < -1
        || _range.max() > std::numeric_limits<unsigned short>::max())
        throw exception::invalid_argument("The maximum value of the quantifier "
                                          "range exceeds the valid limits.");
}


token_type quantifier::get_type() const
{
    return token_type::quantifier;
}


const std::string& quantifier::get_source() const
{
    return _source;
}


operator_precedence
    quantifier::get_operator_precedence_over(const i_token& other) const
{
    return get_operator_precedence_over(other.get_type());
}


operator_precedence
    quantifier::get_operator_precedence_over(const token_type& other) const
{
    switch (other) {
    case token_type::quantifier:
        return operator_precedence::equal;
    default:
        return operator_precedence::higher;
    }
}


std::unique_ptr<i_token> quantifier::clone() const
{
    return std::make_unique<quantifier>(_source, _range);
}


void quantifier::add_to_ast_parser(i_ast_parser& parser) const
{
    parser.add_quantifier(*this);
}


void quantifier::apply_to_ast_parser(i_ast_parser& parser) const
{
    parser.apply_quantifier_from_stack(*this);
}


bool quantifier::operator==(const i_token& other) const
{
    return this->get_type() == other.get_type()
           && this->_source == other.get_source();
}


bool quantifier::operator!=(const i_token& other) const
{
    return !(*this == other);
}

// quantifier_range quantifier::get_range() const
// {
//     return quantifier_range();
// }


NAMESPACE_END(regex::parser)