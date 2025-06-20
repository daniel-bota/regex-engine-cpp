#ifndef _REGEX_PARSER_I_LEXER_H
#define _REGEX_PARSER_I_LEXER_H

#include "framework/macros.h"

#include "parser/interface/i_parser.h"

namespace regex::parser
{
    class i_token;
}

namespace regex::parser
{
    class i_lexer : public i_parser
    {
        INTERFACE(i_lexer)
    public:
        virtual i_token* const get_token() const = 0;

    protected:
    };
}

#endif //_REGEX_PARSER_I_LEXER_H