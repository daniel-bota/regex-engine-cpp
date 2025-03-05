#ifndef _REGEX_PARSER_I_SYNTAX_TREE_H
#define _REGEX_PARSER_I_SYNTAX_TREE_H

#include "framework/macros.h"

#include <memory>
#include <string>

namespace regex::parser
{
    class i_node;
    class i_token;
}

namespace regex::parser
{
    enum class tree_traversal
    {
        // dfs_pre_order,
        dfs_post_order,
        // dfs_in_order,
        // bfs
    };

    class i_syntax_tree
    {
        INTERFACE(i_syntax_tree)
    public:
        virtual i_node* root() const = 0;
        virtual void set_root(std::unique_ptr<i_node> node) = 0;
        virtual std::unique_ptr<i_node>
            create_node(std::unique_ptr<i_token>) const = 0;
        virtual std::unique_ptr<i_node>
            create_node(const i_token* const) const = 0;
        virtual std::string print(const tree_traversal&) const = 0;

    protected:
    };
}

#endif //_REGEX_PARSER_I_SYNTAX_TREE_H