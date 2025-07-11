#ifndef _REGEX_PARSER_CHARACTER_H
#define _REGEX_PARSER_CHARACTER_H

#include "parser/interface/i_token.h"

NAMESPACE_BEGIN(regex::parser)

class character : public i_token
{
public:
    explicit character(const std::string& source);
    explicit character(const character&);
    token_type get_type() const override;
    // operator_type get_operator_type() const override;
    // const quantifier& get_quantifier() const override;
    const std::string& get_source() const override;
    operator_precedence
        get_operator_precedence_over(const i_token&) const override;
    operator_precedence
        get_operator_precedence_over(const token_type&) const override;
    std::unique_ptr<i_token> clone() const override;
    void add_to_ast_parser(i_ast_parser&) const override;
    void apply_to_ast_parser(i_ast_parser&) const override;

    bool operator==(const i_token& other) const override;

protected:
    character() = delete;

private:
    std::string _source;
};

NAMESPACE_END(regex::parser)

#endif // _REGEX_PARSER_CHARACTER_H
