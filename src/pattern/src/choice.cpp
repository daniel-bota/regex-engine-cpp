#include "choice.h"
#include "match_result.h"


regex::choice::~choice()
{
}


void regex::choice::add(std::unique_ptr<ipattern> pattern)
{
    if (!pattern)
        return;

    _patterns.push_back(std::move(pattern));
}


std::unique_ptr<regex::imatch_result> regex::choice::match(const std::string& target) const
{
    if (target.empty())
        return std::make_unique<regex::match_result>(false, std::string(), target);

    for (const std::unique_ptr<ipattern>& pattern : _patterns) {
        auto pattern_match = pattern->match(target);

        if (pattern_match->success()) {
            return std::make_unique<regex::match_result>(
                true, pattern_match->prefix(), pattern_match->suffix());
        }
    }

    return std::make_unique<regex::match_result>(false, std::string(), target);
}
