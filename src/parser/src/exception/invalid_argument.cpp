#include "parser/exception/invalid_argument.h"

#include "framework/macros.h"


NAMESPACE_BEGIN(regex::parser::exception)


invalid_argument::invalid_argument(const std::string& message)
    : basic_error(message)
{
}


NAMESPACE_END(regex::parser::exception)
