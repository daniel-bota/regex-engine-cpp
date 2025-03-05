#ifndef _REGEX_PARSER_QUANTIFIER_H
#define _REGEX_PARSER_QUANTIFIER_H

#include "parser/interface/i_token.h"

#include <string>

namespace regex::parser
{
    class quantifier : public i_token
    {
    public:
        quantifier();
        using quantifier_range = std::pair<int, int>;
        quantifier(const std::string& source, const quantifier_range& range);
        bool add_to_ast_parser(i_ast_parser*) const override;
        bool apply_to_ast_parser(i_ast_parser*) const override;
        


        // quantifier_range get_range() const override;

    private:
        std::string _source;
        quantifier_range _range;
    };
}

#endif //_REGEX_PARSER_QUANTIFIER_H