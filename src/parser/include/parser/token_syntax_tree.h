#ifndef _REGEX_PARSER_SYNTAX_TREE_H
#define _REGEX_PARSER_SYNTAX_TREE_H

#include "parser/interface/i_token_ast.h"

#include <memory>

namespace regex::parser
{
    class token_syntax_tree : public i_token_ast
    {
    public:
        // i_binary_token_node* const root() const override;
        void set_root(std::unique_ptr<i_binary_token_node> node) override;
        /*
        Moves the specified i_token to the created node.

        if token is null -> throws
        regex::parser::exception::invalid_argument exception.
        */
        std::unique_ptr<i_binary_token_node>
            create_node(std::unique_ptr<i_token> token) const override;
        /*
        Creates a new node with a clone of the specified i_token.

        If token is null -> throws
        regex::parser::exception::invalid_argument exception.
        */
        std::unique_ptr<i_binary_token_node>
            create_node(const i_token* const) const override;
        /*
        Creates a new node with a clone of the specified i_token.
        */
        std::unique_ptr<i_binary_token_node>
            create_node(const i_token& token) const override;
        /*
        Returns a string created by concatenating the sources of the tokens in
        the nodes. The nodes are traversed in the order dictated by the
        specified traversal type.

        Throws regex::parser::exception::invalid_argument exception if the
        specified traversal type is not supported.
        */
        std::string print(const tree_traversal& traversal) const override;
        /*
        Returns a std::vector<std::string> that contains the sources of the
        tokens in the nodes. The nodes are traversed in the order dictated by
        the specified traversal type.

        Throws regex::parser::exception::invalid_argument exception if
        the specified traversal type is not supported.
        */
        std::vector<std::string>
            print_node_list(const tree_traversal& traversal) const override;

    private:
        std::unique_ptr<i_binary_token_node> _root;

        std::vector<std::string> get_token_sources_dfs_post_order() const;
    };
}

#endif // _REGEX_PARSER_SYNTAX_TREE_H