#ifndef _REGEX_PARSER_BINARY_TOKEN_NODE_H
#define _REGEX_PARSER_BINARY_TOKEN_NODE_H

#include "parser/interface/i_token_ast.h"

namespace regex::parser
{
    class i_token;

    class binary_token_node : public i_binary_token_node
    {
    public:
        /*
        Takes ownership of the specified i_token.

        If token is null -> throws
        regex::parser::exception::invalid_argument exception.
        */
        explicit binary_token_node(std::unique_ptr<i_token> token);
        /*
        Clones the specified token and takes ownership of the resulting
        i_token.

        If token is null -> throws
        regex::parser::exception::invalid_argument exception.
        */
        explicit binary_token_node(const i_token* const token);
        /*
        Clones the specified i_token and takes ownership of the resulting
        object.
        */
        explicit binary_token_node(const i_token& token);

        i_binary_token_node* left() const override;
        i_binary_token_node* right() const override;
        bool is_leaf() const override;
        void set_left(std::unique_ptr<i_binary_token_node>) override;
        void set_right(std::unique_ptr<i_binary_token_node>) override;

        const i_token& get_token() const override;

    protected:
        binary_token_node() = delete;

    private:
        std::unique_ptr<i_binary_token_node> _left;
        std::unique_ptr<i_binary_token_node> _right;
        std::unique_ptr<i_token> _token;
    };
}

#endif //_REGEX_PARSER_BINARY_TOKEN_NODE_H