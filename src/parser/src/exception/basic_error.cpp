#include "parser/exception/basic_error.h"

#include "framework/macros.h"

NAMESPACE_BEGIN(regex::parser::exception)


basic_error::basic_error(const std::string& message)
    : std::logic_error(message.c_str())
{
}

// std::string basic_error::message() const
// {
//     return std::string(this->what());
// }


NAMESPACE_END(regex::parser::exception)