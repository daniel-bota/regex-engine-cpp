#ifndef _REGEX_PARSER_IOPERATOR_H
#define _REGEX_PARSER_IOPERATOR_H

#include "framework/macros.h"

namespace regex::parser
{
    enum node_type;
    class inode
    {
        INTERFACE(inode)
    public:
        virtual node_type type() = 0;

    protected:
        inode() = default;
    };
}

#endif //_REGEX_PARSER_IOPERATOR_H