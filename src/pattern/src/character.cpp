#include "character.h"
#include "match_result.h"

regex::character::character(const char& ch)
    : _character(ch)
{
}


std::unique_ptr<regex::imatch_result> regex::character::match(const std::string& target) const
{
    bool matched = !target.empty() && target.at(0) == _character;
    if (!matched) {

        return std::make_unique<regex::match_result>(false, std::string(), target);
    }

    return std::make_unique<regex::match_result>(true, std::string(), target.substr(1, target.size()));
}
