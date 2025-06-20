#ifndef _REGEX_PARSER_BASIC_PARSER_H
#define _REGEX_PARSER_BASIC_PARSER_H

#include <memory>
#include <parser/interface/i_ast_parser.h>
#include <stack>

namespace regex::parser
{
    class i_token;
    enum class token_type;
    class i_lexer;
    class i_binary_token_node;
    class i_token_ast;
}

namespace regex::parser
{
    class basic_parser : public i_ast_parser
    {
    public:
        /*
        Takes ownership of the specified i_lexer.

        Throws regex::parser::exception::invalid_argument exception if
        lexer is null.
        */
        explicit basic_parser(std::unique_ptr<i_lexer> lexer);
        ~basic_parser();
        /*
        Transforms the specified regular expression into an abstract syntax
        tree.

        Throws a regex::parser::exception::invalid_regex exception if an error
        occurs.
        */
        void compute(const std::string& regex);
        const i_token_ast& get_syntax_tree() const override;
        void add_operator_token(const i_token&);
        void apply_binary_operator_from_stack(const i_token&);
        /*
        Adds a clone of the specified character token to the argument stack. If
        the argument stack is not empty, adds a concatenation token to the
        top of the operand stack.
        */
        void add_character(const character&) override;
        /*
        Adds a new concatenation token to the operator stack.

        Throws regex::parser::exception::invalid_expression exception if
        _argument_stack is empty or another error occurs.
        */
        void add_concatenation() override;
        /*
        Adds a clone of the specified quantiier token to the operator stack.

        Throws regex::parser::exception::invalid_expression exception if
        _argument_stack is empty.
        */
        void add_quantifier(const quantifier&) override;
        /*
        Adds a clone of the specified alternative token to the operator stack.

        Throws regex::parser::exception::invalid_expression exception if
        _argument_stack is empty.
        */
        void add_alternative(const alternative&) override;
        /*
        Applies the operator from the top of the operator stack if it matches
        the specified concatenation token.

        Throws regex::parser::exception::invalid_expression exception if
        an error ocurs.
        */
        void apply_concatenation_from_stack(const concatenation&) override;
        /*
        Applies the operator from the top of the operator stack if it matches
        the specified quantifier token.

        Throws regex::parser::exception::invalid_expression exception if
        an error ocurs.
        */
        void apply_quantifier_from_stack(const quantifier&) override;
        /*
        Applies the operator from the top of the operator stack if it matches
        the specified alternative token.

        Throws regex::parser::exception::invalid_expression exception if
        an error ocurs.
        */
        void apply_alternative_from_stack(const alternative&) override;

    protected:
    private:
        std::stack<std::unique_ptr<i_binary_token_node>> _argument_stack;
        std::stack<std::unique_ptr<i_binary_token_node>> _operator_stack;
        std::unique_ptr<i_token_ast> _syntax_tree;
        std::unique_ptr<i_lexer> _lexer;
        bool concatenate_next_character{false};

        /*
        Clears all stacks and the syntax tree.
        */
        void clear();
        std::unique_ptr<i_token_ast> create_syntax_tree();
        /*
        Cosumes the first token from the input string and adds it to the
        corresponding stack (argument or operator).

        Throws regex::parser::exception::invalid_regex exception if an error
        occurs.
        */
        void consume_first_token(std::string& input);
        /*
        Applies operators from the top of the operator stack if they have higher
        precedence than the specified operator.

        Throws regex::parser::exception::invalid_regex exception if an error
        occurs.
        */
        void apply_higher_precedence_operators(
            const token_type& incoming_operator);
        /*
        Applies all operators from the the operator stack.

        Throws regex::parser::exception::invalid_regex exception if an error
        occurs.
        */
        void apply_all_operators();
    };
}

#endif //_REGEX_PARSER_BASIC_PARSER_H