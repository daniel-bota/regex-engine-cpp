#ifndef _REGEX_PARSER_EXCEPTION_INVALID_REGEX_H
#define _REGEX_PARSER_EXCEPTION_INVALID_REGEX_H

#include "parser/exception/basic_error.h"

#include <string>

namespace regex::parser::exception
{
    class invalid_regex : public basic_error
    {
    public:
        explicit invalid_regex(const std::string& message);

    protected:
    private:
    };
}

#endif // _REGEX_PARSER_EXCEPTION_INVALID_REGEX_H