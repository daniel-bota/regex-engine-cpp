#ifndef _REGEX_PARSER_I_PARSER_H
#define _REGEX_PARSER_I_PARSER_H

#include "framework/macros.h"

#include <string>

namespace regex::parser
{
    class i_parser
    {
        INTERFACE(i_parser)
    public:
        /*
         * throws exception
         */
        virtual void compute(const std::string& regex) = 0;

    protected:
    };
}

#endif //_REGEX_PARSER_I_PARSER_H