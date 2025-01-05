#include "concatenation.h"

#include "framework/macros.h"
#include "operator_type.h"

NAMESPACE_BEGIN(regex::parser)


concatenation::concatenation(inode* left, inode* right)
    : inode(), _left(left), _right(right)
{
    _type = node_type::concatenation;
}

node_type concatenation::type()
{
    return _type;
}


inode* concatenation::right()
{
    return _right;
}


inode* concatenation::left()
{
    return _left;
}

NAMESPACE_END(regex::parser)