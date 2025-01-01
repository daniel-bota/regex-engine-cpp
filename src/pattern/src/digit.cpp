#include "digit.h"
#include "match_result.h"


std::unique_ptr<regex::imatch_result> regex::digit::match(const std::string& target) const
{
    if (target.empty() || !std::isdigit(target.at(0))) {
        return std::make_unique<regex::match_result>(false, std::string(), target);
    }

    return std::make_unique<regex::match_result>(true, std::string(), target.substr(1, target.size()));
}