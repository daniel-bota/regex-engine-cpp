#ifndef _REGEX_PARSER_OPERATOR_TYPE_H
#define _REGEX_PARSER_OPERATOR_TYPE_H

namespace regex::parser
{
    enum node_type
    {
        character,
        epsilon,
        concatenation,
        choice,
        closure
    };
}

#endif //_REGEX_PARSER_OPERATOR_TYPE_H