#ifndef _REGEX_PARSER_I_AST_PARSER_H
#define _REGEX_PARSER_I_AST_PARSER_H

#include "framework/macros.h"

#include "parser/interface/i_parser.h"

#include <string>

namespace regex::parser
{
    class i_syntax_tree;
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
        virtual i_syntax_tree* get_syntax_tree() const = 0;
        virtual bool add_character(const character* const) = 0;
        virtual bool add_concatenation() = 0;
        virtual bool add_quantifier(const quantifier* const) = 0;
        virtual bool apply_concatenation_from_stack(const concatenation* const) = 0;
        virtual bool apply_quantifier_from_stack(const quantifier* const) = 0;

    protected:
    };
}

#endif //_REGEX_PARSER_I_AST_PARSER_H