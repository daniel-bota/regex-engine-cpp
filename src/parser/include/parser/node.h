#ifndef _REGEX_PARSER_NODE_H
#define _REGEX_PARSER_NODE_H

#include "parser/interface/i_node.h"

namespace regex::parser
{
    class i_token;

    class node : public i_node
    {
    public:
        /*
        Takes ownership of the specified i_token.

        If token is null -> throws
        regex::parser::exception::invalid_argument exception.
        */
        explicit node(std::unique_ptr<i_token> token);
        /*
        Clones the specified token and takes ownership of the resulting
        i_token.

        If token is null -> throws
        regex::parser::exception::invalid_argument exception.
        */
        explicit node(const i_token* const token);
        /*
        Clones the specified i_token and takes ownership of the resulting
        object.
        */
        explicit node(const i_token& token);

        i_node* left() const override;
        i_node* right() const override;
        const i_token& get_token() const override;
        bool is_leaf() const override;
        void set_left(std::unique_ptr<i_node>) override;
        void set_right(std::unique_ptr<i_node>) override;

    protected:
        node() = delete;

    private:
        std::unique_ptr<i_node> _left;
        std::unique_ptr<i_node> _right;
        std::unique_ptr<i_token> _token;
    };
}

#endif //_REGEX_PARSER_NODE_H