#ifndef _REGEX_PARSER_TOKEN_PARSER_H
#define _REGEX_PARSER_TOKEN_PARSER_H

#include "parser/interface/i_token_parser.h"

#include <memory>

namespace regex::parser
{
    class i_token;
}

namespace regex::parser
{
    class token_parser : public i_token_parser
    {
    public:
        ~token_parser();
        parse_result compute(const std::string& source) override;
        i_token* get_token() const override;

    private:
        std::unique_ptr<i_token> _token;
    };
}

#endif _REGEX_PARSER_TOKEN_PARSER_H