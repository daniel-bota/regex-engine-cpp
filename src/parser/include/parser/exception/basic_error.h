#ifndef _REGEX_PARSER_EXCEPTION_BASIC_H
#define _REGEX_PARSER_EXCEPTION_BASIC_H

#include <exception>
#include <string>

namespace regex::parser::exception
{
    class basic_error : public std::exception
    {
    public:
        // std::string message() const;

    protected:
        explicit basic_error(const std::string& message);

    private:
    };
}

#endif // _REGEX_PARSER_EXCEPTION_BASIC_H