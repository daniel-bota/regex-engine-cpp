#ifndef _REGEX_PARSER_CONCATENATION_H
#define _REGEX_PARSER_CONCATENATION_H

#include "inode.h"

namespace regex::parser
{
    class concatenation : public inode
    {
    public:
        concatenation(inode* left, inode* right);
        node_type type() override;

    private:
        node_type _type;
        inode* _left;
        inode* _right;
    };
}

#endif _REGEX_PARSER_CONCATENATION_H