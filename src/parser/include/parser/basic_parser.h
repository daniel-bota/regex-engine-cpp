#ifndef _REGEX_PARSER_BASIC_PARSER_H
#define _REGEX_PARSER_BASIC_PARSER_H

#include <deque>
#include <memory>
#include <parser/interface/i_ast_parser.h>
#include <stack>

namespace regex::parser
{
    enum class token_type;
    class i_token_parser;
    class i_node;
    class i_syntax_tree;
}

namespace regex::parser
{
    class basic_parser : public i_ast_parser
    {
    public:
        basic_parser(std::unique_ptr<i_token_parser> token_parser);
        ~basic_parser();

        parse_result compute(const std::string& regex);
        i_syntax_tree* get_syntax_tree() const override;
        bool add_character(const character* const) override;
        bool add_concatenation() override;
        bool add_quantifier(const quantifier* const) override;
        bool
            apply_concatenation_from_stack(const concatenation* const) override;
        bool apply_quantifier_from_stack(const quantifier* const) override;


    protected:
    private:
        // std::deque<i_node> _nodes;
        std::stack<std::unique_ptr<i_node>> _argument_stack;
        std::stack<std::unique_ptr<i_node>> _operator_stack;
        std::unique_ptr<i_syntax_tree> _syntax_tree;
        std::unique_ptr<i_token_parser> _token_parser;

        std::unique_ptr<i_syntax_tree> create_syntax_tree();
        parse_result consume_first_token(std::string& input);
        bool apply_higher_precedence_operators(const token_type&);
        bool apply_all_operators();
    };
}

#endif //_REGEX_PARSER_BASIC_PARSER_H