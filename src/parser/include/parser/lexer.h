#ifndef _REGEX_PARSER_LEXER_H
#define _REGEX_PARSER_LEXER_H

#include "parser/interface/i_lexer.h"

#include <memory>

namespace regex::parser
{
    class i_token;
}

namespace regex::parser
{
    class lexer : public i_lexer
    {
    public:
        ~lexer();
        void compute(const std::string& source) override;
        i_token* const get_token() const override;

    private:
        std::unique_ptr<i_token> _token;
    };
}

#endif _REGEX_PARSER_LEXER_H