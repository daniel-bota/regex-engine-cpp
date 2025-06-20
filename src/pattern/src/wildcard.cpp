#include "wildcard.h"

#include "match_result.h"

std::unique_ptr<regex::imatch_result>
    regex::wildcard::match(const std::string& target) const
{
    if (target.empty()) {
        return std::make_unique<match_result>(false, std::string(), target);
    }
    return std::make_unique<match_result>(
        true, std::string(), target.substr(1, target.size()));
}