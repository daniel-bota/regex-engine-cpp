#ifndef _REGEX_PARSER_EXCEPTION_INVALID_ARGUMENT_H
#define _REGEX_PARSER_EXCEPTION_INVALID_ARGUMENT_H

#include "parser/exception/basic_error.h"

#include <string>

namespace regex::parser::exception
{
    class invalid_argument : public basic_error
    {
    public:
        explicit invalid_argument(const std::string&);

    protected:
    private:
    };
}

#endif // _REGEX_PARSER_EXCEPTION_INVALID_ARGUMENT_H