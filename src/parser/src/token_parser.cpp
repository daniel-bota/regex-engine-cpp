#include "parser/alternative.h"
#include "parser/character.h"
#include "parser/interface/i_token.h"
#include "parser/interface/i_token_ast.h"
#include "parser/lexer.h"
#include "parser/quantifier.h"

#include <framework/macros.h>

NAMESPACE_BEGIN(regex::parser)


namespace
{
    constexpr const char kleene_closure{'*'};
    constexpr const char alternative_source{'|'};

    const quantifier::range kleene_closure_range{0, -1};
}


lexer::~lexer()
{
}


void lexer::compute(const std::string& source)
{
    switch (source.front()) {
    case kleene_closure:
        _token = std::make_unique<quantifier>(std::string{source.front()},
                                              kleene_closure_range);
        return;
    case alternative_source:
        _token = std::make_unique<alternative>(std::string{source.front()});
        return;
    default:
        _token = std::make_unique<character>(source);
        break;
    }
}


i_token* const lexer::get_token() const
{
    return _token.get();
}


NAMESPACE_END(regex::parser)