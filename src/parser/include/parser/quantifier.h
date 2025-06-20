#ifndef _REGEX_PARSER_QUANTIFIER_H
#define _REGEX_PARSER_QUANTIFIER_H

#include "parser/interface/i_token.h"

#include <string>

namespace regex::parser
{
    class quantifier : public i_token
    {
    public:
        class range
        {
        public:
            range(const unsigned short& min, const int& max);
            unsigned short min() const;
            int max() const;
        private:
            unsigned short _min;
            int _max;
        };

        quantifier(const std::string& source, const range& range);

        token_type get_type() const override;
        const std::string& get_source() const override;
        operator_precedence
            get_operator_precedence_over(const i_token&) const override;
        operator_precedence
            get_operator_precedence_over(const token_type&) const override;
        std::unique_ptr<i_token> clone() const override;

        void add_to_ast_parser(i_ast_parser&) const override;
        void apply_to_ast_parser(i_ast_parser&) const override;

        bool operator==(const i_token&) const override;


        // quantifier_range get_range() const override;

    private:
        std::string _source;
        range _range;
    };
}

#endif //_REGEX_PARSER_QUANTIFIER_H