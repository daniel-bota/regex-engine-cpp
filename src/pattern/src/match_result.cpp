#include "match_result.h"

regex::match_result::match_result(bool success, const std::string& prefix, const std::string& suffix)
    : _success(success), _prefix(prefix), _suffix(suffix)
{
}


bool regex::match_result::success() const
{
    return _success;
}


const std::string& regex::match_result::prefix() const
{
    return _prefix;
}


const std::string& regex::match_result::suffix() const
{
    return _suffix;
}
