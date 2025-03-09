#ifndef _REGEX_PARSER_I_PARSER_H
#define _REGEX_PARSER_I_PARSER_H

#include "framework/macros.h"

#include <string>

namespace regex::parser
{
    enum class parse_status
    {
        success,
        failure
    };

    struct parse_result
    {
        parse_status status;
        std::string message;

        bool operator==(const parse_result& other) const
        {
            return status == other.status && message == other.message;
        }
    };

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