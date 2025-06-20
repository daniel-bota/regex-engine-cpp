#ifndef _REGEX_PARSER_I_TOKEN_H
#define _REGEX_PARSER_I_TOKEN_H

#include "framework/macros.h"

#include <memory>
#include <string>

namespace regex::parser
{
    enum class token_type;
    enum class operator_precedence;
    class i_ast_parser;
}

NAMESPACE_BEGIN(regex::parser)

class i_token
{
    INTERFACE(i_token)

public:
    virtual token_type get_type() const = 0;
    // virtual operator_type get_operator_type() const = 0;
    // virtual const quantifier& get_quantifier() const = 0;
    virtual const std::string& get_source() const = 0;
    virtual operator_precedence get_operator_precedence_over(const i_token&) const = 0;
    virtual operator_precedence get_operator_precedence_over(const token_type&) const = 0;
    virtual std::unique_ptr<i_token> clone() const = 0;

    virtual void add_to_ast_parser(i_ast_parser&) const = 0;
    virtual void apply_to_ast_parser(i_ast_parser&) const = 0;

    virtual bool operator==(const i_token&) const = 0;
    virtual bool operator!=(const i_token&) const = 0;

protected:
};

enum class token_type
{
    sequence = -4,
    structure,
    token,
    capture,
    character = 0,
    alternative,
    concatenation,
    quantifier
};

enum class operator_precedence
{
    none,
    lower,
    equal,
    higher
};

NAMESPACE_END(regex::parser)

#endif //_REGEX_PARSER_I_TOKEN_H