#include "parser/basic_parser.h"

#include "parser/character.h"
#include "parser/concatenation.h"
#include "parser/interface/i_node.h"
#include "parser/interface/i_token.h"
#include "parser/quantifier.h"
#include "parser/syntax_tree.h"
#include "parser/token_parser.h"

#include <iostream>

NAMESPACE_BEGIN(regex::parser)


basic_parser::basic_parser(std::unique_ptr<i_token_parser> token_parser)
    : _token_parser(std::move(token_parser))

{
}


basic_parser::~basic_parser()
{
}


std::unique_ptr<i_syntax_tree> basic_parser::create_syntax_tree()
{
    return std::make_unique<syntax_tree>();
}


parse_result basic_parser::consume_first_token(std::string& input)
{
    parse_result token_result = _token_parser->compute(input);
    if (parse_status::failure == token_result.status)
        return token_result;

    if (!_token_parser->get_token()->add_to_ast_parser(this))
        return {parse_status::failure, "Invalid expression."};

    input = input.substr(_token_parser->get_token()->get_source().size(),
                         input.size());
    return {parse_status::success, std::string()};
}


bool basic_parser::apply_higher_precedence_operators(const token_type& incoming)
{
    while (!_operator_stack.empty()) {
        operator_precedence top_stack_precedence =
            _operator_stack.top()->get_token()->get_operator_precedence(
                incoming);
        if (operator_precedence::none == top_stack_precedence)
            return false;
        if (operator_precedence::lower == top_stack_precedence)
            return true;

        if (!_operator_stack.top()->get_token()->apply_to_ast_parser(this))
            return false;
    }

    return true;
}


bool basic_parser::apply_all_operators()
{
    while (!_operator_stack.empty()) {
        if (!_operator_stack.top()->get_token()->apply_to_ast_parser(this))
            return false;
    }

    return true;
}


parse_result basic_parser::compute(const std::string& regex)
{
    std::cout << "basic_parser parsing regex: " << "\"" << regex << "\"...\n";
    _syntax_tree = std::move(create_syntax_tree());
    _argument_stack = std::stack<std::unique_ptr<i_node>>();
    _operator_stack = std::stack<std::unique_ptr<i_node>>();
    std::string input{regex};

    while (!input.empty()) {
        parse_result first_token_result = consume_first_token(input);
        if (parse_status::failure == first_token_result.status)
            return first_token_result;
    }
    apply_all_operators();
    _syntax_tree->set_root(std::move(_argument_stack.top()));
    _argument_stack.pop();

    return {parse_status::success, std::string()};
}


i_syntax_tree* basic_parser::get_syntax_tree() const
{
    return _syntax_tree.get();
}


bool basic_parser::add_character(const character* const character_token)
{
    if (!_argument_stack.empty())
        add_concatenation();
    _argument_stack.emplace(_syntax_tree->create_node(character_token));
    return true;
}


bool basic_parser::add_concatenation()
{
    if (_argument_stack.empty())
        return false;

    if (!apply_higher_precedence_operators(token_type::concatenation))
        return false;

    _operator_stack.emplace(
        _syntax_tree->create_node(std::make_unique<concatenation>()));
    return true;
}


bool basic_parser::add_quantifier(const quantifier* const quantifier_token)
{
    if (_argument_stack.empty())
        return false;

    _operator_stack.emplace(_syntax_tree->create_node(quantifier_token));
    return true;
}


bool basic_parser::apply_concatenation_from_stack(
    const concatenation* const top_node)
{
    if (_operator_stack.empty())
        return false;
    if (_operator_stack.top()->get_token() != top_node)
        return false;

    if (_argument_stack.size() < 2)
        return false;

    _operator_stack.top()->set_right(std::move(_argument_stack.top()));
    _argument_stack.pop();
    _operator_stack.top()->set_left(std::move(_argument_stack.top()));
    _argument_stack.pop();

    _argument_stack.emplace(std::move(_operator_stack.top()));
    _operator_stack.pop();
    return true;
}


bool basic_parser::apply_quantifier_from_stack(const quantifier* const)
{
    return false;
}


NAMESPACE_END(regex::parser)