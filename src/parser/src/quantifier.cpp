#include "parser/quantifier.h"

#include "parser/interface/i_ast_parser.h"

NAMESPACE_BEGIN(regex::parser)

quantifier::quantifier()
{
    _source = std::string();
    _range = {1, 1};
}


quantifier::quantifier(const std::string& source, const quantifier_range& range)
{
    _source = source;
    _range = range;
}


void quantifier::add_to_ast_parser(i_ast_parser& parser) const
{
    parser.add_quantifier(*this);
}

void quantifier::apply_to_ast_parser(i_ast_parser& parser) const
{
    parser.apply_quantifier_from_stack(*this);
}


// quantifier_range quantifier::get_range() const
// {
//     return quantifier_range();
// }


NAMESPACE_END(regex::parser)