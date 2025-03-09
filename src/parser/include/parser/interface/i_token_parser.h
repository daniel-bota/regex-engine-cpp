#ifndef _REGEX_PARSER_I_TOKEN_PARSER_H
#define _REGEX_PARSER_I_TOKEN_PARSER_H

#include "framework/macros.h"

#include "parser/interface/i_parser.h"

namespace regex::parser
{
    class i_token;
}

namespace regex::parser
{
    class i_token_parser : public i_parser
    {
        INTERFACE(i_token_parser)
    public:
        virtual i_token* const get_token() const = 0;

    protected:
    };
}

#endif //_REGEX_PARSER_I_TOKEN_PARSER_H