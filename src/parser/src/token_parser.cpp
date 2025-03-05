#include "parser/token_parser.h"

#include "parser/character.h"
#include "parser/interface/i_token.h"
#include "parser/interface/i_node.h"
#include "parser/syntax_tree.h"

#include <framework/macros.h>

NAMESPACE_BEGIN(regex::parser)


token_parser::~token_parser()
{
}


parse_result token_parser::compute(const std::string& source)
{
    _token = std::make_unique<character>(source);
    return {parse_status::success, std::string()};
}


i_token* token_parser::get_token() const
{
    return _token.get();
}


NAMESPACE_END(regex::parser)