#include "parser/token_parser.h"

#include "parser/character.h"
#include "parser/interface/i_node.h"
#include "parser/interface/i_token.h"
#include "parser/quantifier.h"
#include "parser/syntax_tree.h"

#include <framework/macros.h>

NAMESPACE_BEGIN(regex::parser)


namespace
{
    constexpr char kleene_closure{'*'};

    const quantifier::range kleene_closure_range{0, -1};
}


token_parser::~token_parser()
{
}


void token_parser::compute(const std::string& source)
{
    if (source.front() == kleene_closure) {
        _token = std::make_unique<quantifier>(source.substr(0, 1),
                                              kleene_closure_range);
        return;
    }
    _token = std::make_unique<character>(source);
}


i_token* const token_parser::get_token() const
{
    return _token.get();
}


NAMESPACE_END(regex::parser)