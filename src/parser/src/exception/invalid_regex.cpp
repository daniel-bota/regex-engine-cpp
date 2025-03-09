#include "parser/exception/invalid_regex.h"

#include <framework/macros.h>


NAMESPACE_BEGIN(regex::parser::exception)


invalid_regex::invalid_regex(const std::string& message)
    : basic_error(message)
{
}


NAMESPACE_END(regex::parser::exception)