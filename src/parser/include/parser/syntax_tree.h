#ifndef _REGEX_PARSER_SYNTAX_TREE_H
#define _REGEX_PARSER_SYNTAX_TREE_H

#include "parser/interface/i_syntax_tree.h"

#include <memory>

namespace regex::parser
{
    class syntax_tree : public i_syntax_tree
    {
    public:
        i_node* root() const override;
        void set_root(std::unique_ptr<i_node> node) override;
        std::unique_ptr<i_node>
            create_node(std::unique_ptr<i_token> token) const override;
        std::unique_ptr<i_node>
            create_node(const i_token* const token) const override;
        std::string print(const tree_traversal& traversal) const override;

    private:
        std::unique_ptr<i_node> _root;

        std::string print_dfs_post_order() const;
    };
}

#endif // _REGEX_PARSER_SYNTAX_TREE_H