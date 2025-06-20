#ifndef _REGEX_PARSER_I_TOKEN_AST_H
#define _REGEX_PARSER_I_TOKEN_AST_H

#include "framework/macros.h"

#include <memory>
#include <string>
#include <vector>


NAMESPACE_BEGIN(regex::parser)

class i_token;
class i_binary_token_node;
enum class tree_traversal;

class i_token_ast
{
    INTERFACE(i_token_ast)

public:
    // i_binary_token_node* const root() const = 0;
    virtual void
        set_root(std::unique_ptr<i_binary_token_node> i_binary_token_node) = 0;
    /*
     * throws exception
     */
    virtual std::unique_ptr<i_binary_token_node>
        create_node(std::unique_ptr<i_token>) const = 0;
    virtual std::unique_ptr<i_binary_token_node>
        create_node(const i_token* const) const = 0;
    virtual std::unique_ptr<i_binary_token_node>
        create_node(const i_token&) const = 0;
    virtual std::string print_token_sources(const tree_traversal&) const = 0;
    virtual std::vector<std::string>
        get_token_source_list(const tree_traversal&) const = 0;
    virtual std::vector<const i_token*>
        get_token_list(const tree_traversal&) const = 0;

protected:
};

template<class T>
class i_binary_node
{
    INTERFACE(i_binary_node)

public:
    virtual T* left() const = 0;
    virtual T* right() const = 0;
    virtual bool is_leaf() const = 0;
    virtual void set_left(std::unique_ptr<T>) = 0;
    virtual void set_right(std::unique_ptr<T>) = 0;
};

class i_token_node
{
    INTERFACE(i_token_node)

public:
    virtual const i_token& get_token() const = 0;
};

class i_binary_token_node : public i_binary_node<i_binary_token_node>,
                            public i_token_node
{
    INTERFACE(i_binary_token_node)
};

enum class tree_traversal
{
    // dfs_pre_order,
    dfs_post_order,
    // dfs_in_order,
    // bfs
};

NAMESPACE_END(regex::parser)

#endif //_REGEX_PARSER_I_TOKEN_AST_H