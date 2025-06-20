#ifndef _REGEX_PARSER_I_AST_PARSER_H
#define _REGEX_PARSER_I_AST_PARSER_H

#include "framework/macros.h"
#include "parser/interface/i_parser.h"

#include <string>

namespace regex::parser
{
    class i_token_ast;
    class i_token;
    class alternative;
    class character;
    class concatenation;
    class quantifier;
}

namespace regex::parser
{
    class i_ast_parser : public i_parser
    {
        INTERFACE(i_ast_parser)
    public:
        virtual const i_token_ast& get_syntax_tree() const = 0;
        virtual void add_character(const i_token&) = 0;
        virtual void add_concatenation() = 0;
        virtual void add_quantifier(const i_token&) = 0;
        virtual void add_alternative(const i_token&) = 0;
        virtual void apply_concatenation_from_stack(const i_token&) = 0;
        virtual void apply_quantifier_from_stack(const i_token&) = 0;
        virtual void apply_alternative_from_stack(const i_token&) = 0;

    protected:
    };
}

#endif //_REGEX_PARSER_I_AST_PARSER_H