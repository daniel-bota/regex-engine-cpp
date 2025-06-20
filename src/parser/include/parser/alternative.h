#ifndef _REGEX_PARSER_ALTERNATIVE_H
#define _REGEX_PARSER_ALTERNATIVE_H

#include "parser/interface/i_token.h"

#include <string>

NAMESPACE_BEGIN(regex::parser)

class alternative : public i_token
{
public:
    explicit alternative(const std::string& source);
    alternative(const alternative& other);
    token_type get_type() const override;
    const std::string& get_source() const override;
    operator_precedence get_operator_precedence_over(const i_token&) const override;
    operator_precedence get_operator_precedence_over(const token_type&) const override;
    std::unique_ptr<i_token> clone() const override;

    void add_to_ast_parser(i_ast_parser&) const override;
    void apply_to_ast_parser(i_ast_parser&) const override;

    bool operator==(const i_token&) const override;

protected:
private:
    std::string _source;
};

NAMESPACE_END(regex::parser)

#endif // _REGEX_PARSER_ALTERNATIVE_H