#include "parser/basic_parser.h"

#include "parser/alternative.h"
#include "parser/character.h"
#include "parser/concatenation.h"
#include "parser/exception/basic_error.h"
#include "parser/exception/invalid_argument.h"
#include "parser/exception/invalid_regex.h"
#include "parser/interface/i_token_ast.h"
#include "parser/interface/i_token.h"
#include "parser/quantifier.h"
#include "parser/token_syntax_tree.h"
#include "parser/lexer.h"

#include <iostream>

NAMESPACE_BEGIN(regex::parser)


basic_parser::basic_parser(std::unique_ptr<i_lexer> lexer)
    : _syntax_tree(create_syntax_tree()),
      _lexer(std::move(lexer))
{
    if (!_lexer)
        throw exception::invalid_argument(
            "The i_lexer passed as an argument to the constructor of "
            "regex::parser::basic_parser cannot be null.");
}


basic_parser::~basic_parser()
{
}


void basic_parser::clear()
{
    _syntax_tree = create_syntax_tree();
    _argument_stack = std::stack<std::unique_ptr<i_binary_token_node>>();
    _operator_stack = std::stack<std::unique_ptr<i_binary_token_node>>();
}

std::unique_ptr<i_token_ast> basic_parser::create_syntax_tree()
{
    return std::make_unique<token_syntax_tree>();
}


void basic_parser::consume_first_token(std::string& input)
{
    _lexer->compute(input);
    if (!_lexer->get_token())
        throw exception::invalid_regex(
            "The token parsed by the token parser is null.");
    _lexer->get_token()->add_to_ast_parser(*this);
    input = input.substr(_lexer->get_token()->get_source().size(),
                         input.size());
}


void basic_parser::apply_higher_precedence_operators(
    const token_type& incoming_operator)
{
    while (!_operator_stack.empty()) {
        operator_precedence top_stack_precedence =
            _operator_stack.top()->get_token().get_operator_precedence_over(
                incoming_operator);
        if (operator_precedence::none == top_stack_precedence)
            throw exception::invalid_regex(
                "The token at the top of the operator stack is not a valid "
                "operator.");
        if (operator_precedence::lower == top_stack_precedence)
            return;
        _operator_stack.top()->get_token().apply_to_ast_parser(*this);
    }
}


void basic_parser::apply_all_operators()
{
    while (!_operator_stack.empty())
        _operator_stack.top()->get_token().apply_to_ast_parser(*this);
}


void basic_parser::compute(const std::string& regex)
{
    std::cout << "basic_parser parsing regex: " << "\"" << regex << "\"...\n";
    clear();
    std::string input{regex};
    concatenate_next_character = false;

    try {
        while (!input.empty())
            consume_first_token(input);

        apply_all_operators();
        _syntax_tree->set_root(std::move(_argument_stack.top()));
        _argument_stack.pop();
    }
    catch (const exception::invalid_regex& ex) {
        clear();
        throw;
    }
    catch (const std::exception& ex) {
        clear();
        throw exception::invalid_regex(
            std::string("An error occurred while parsing the regex (")
            + ex.what() + ").");
    }
    catch (...) {
        clear();
        throw exception::invalid_regex(
            "An unknown error occurred while parsing the regex.");
    }
}


const i_token_ast& basic_parser::get_syntax_tree() const
{
    return *_syntax_tree;
}


void regex::parser::basic_parser::add_operator_token(const i_token& token)
{
    if (_argument_stack.empty())
        throw exception::invalid_regex(
            "The argument stack was empty while "
            "trying to add an operator token to the operator stack.");
    apply_higher_precedence_operators(token.get_type());
    _operator_stack.emplace(_syntax_tree->create_node(token));
}


void regex::parser::basic_parser::apply_binary_operator_from_stack(
    const i_token& expected_token)
{
    if (_operator_stack.empty())
        throw exception::invalid_regex("The argument stack was empty while "
                                       "trying to apply a binary operator from "
                                       "the top of the operator stack.");

    ;
    if (_operator_stack.top()->get_token() != expected_token)
        throw exception::invalid_regex(
            "The token from the top of the operator stack did not match the "
            "expected value.");
    ;

    if (_argument_stack.size() < 2)
        throw exception::invalid_regex(
            "The argument stack had less than 2 elements while "
            "trying too apply a binary operator.");

    _operator_stack.top()->set_right(std::move(_argument_stack.top()));
    _argument_stack.pop();
    _operator_stack.top()->set_left(std::move(_argument_stack.top()));
    _argument_stack.pop();

    _argument_stack.emplace(std::move(_operator_stack.top()));
    _operator_stack.pop();
}


void basic_parser::add_character(const character& character_token)
{
    if (concatenate_next_character)
        add_concatenation();
    _argument_stack.emplace(_syntax_tree->create_node(character_token));
    if (_argument_stack.empty() || !concatenate_next_character)
        concatenate_next_character = true;
}


void basic_parser::add_concatenation()
{
    add_operator_token(concatenation());
}


void basic_parser::add_quantifier(const quantifier& quantifier_token)
{
    add_operator_token(quantifier_token);
}


void basic_parser::add_alternative(const alternative& alternative_token)
{
    add_operator_token(alternative_token);
    concatenate_next_character = false;
}


void basic_parser::apply_concatenation_from_stack(
    const concatenation& expected_token)
{
    apply_binary_operator_from_stack(expected_token);
}


void basic_parser::apply_quantifier_from_stack(const quantifier& expected_token)
{
    if (_operator_stack.empty())
        throw exception::invalid_regex("The argument stack was empty while "
                                       "trying to apply a unary operator from "
                                       "the top of the operator stack.");

    ;
    if (_operator_stack.top()->get_token() != expected_token)
        throw exception::invalid_regex(
            "The token from the top of the operator stack did not match the "
            "expected value.");
    ;

    if (_argument_stack.size() < 1)
        throw exception::invalid_regex(
            "The argument stack had less than 1 element while "
            "trying too apply a unary operator.");

    _operator_stack.top()->set_left(std::move(_argument_stack.top()));
    _argument_stack.pop();

    _argument_stack.emplace(std::move(_operator_stack.top()));
    _operator_stack.pop();
}


void basic_parser::apply_alternative_from_stack(
    const alternative& expected_token)
{
    apply_binary_operator_from_stack(expected_token);
}


NAMESPACE_END(regex::parser)