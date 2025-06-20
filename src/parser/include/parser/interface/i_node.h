#ifndef _REGEX_PARSER_I_NODE_H
#define _REGEX_PARSER_I_NODE_H

#include "framework/macros.h"

#include <memory>

namespace regex::parser
{
    class i_token;
}
namespace regex::parser
{
    class i_node
    {
        INTERFACE(i_node)
    public:
        virtual i_node* left() const = 0;
        virtual i_node* right() const = 0;
        virtual const i_token& get_token() const = 0;
        virtual bool is_leaf() const = 0;
        virtual void set_left(std::unique_ptr<i_node>) = 0;
        virtual void set_right(std::unique_ptr<i_node>) = 0;

    protected:
    };
}

#endif //_REGEX_PARSER_I_NODE_H