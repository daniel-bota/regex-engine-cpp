#include "one_or_more.h"

#include "match_result.h"


regex::one_or_more::one_or_more(std::unique_ptr<ipattern> pattern)
    : _pattern(std::move(pattern))
{
}


std::unique_ptr<regex::imatch_result>
    regex::one_or_more::match(const std::string& target) const
{
    std::string suffix = target;
    std::unique_ptr<imatch_result> result =
        std::make_unique<match_result>(false, std::string(), target);
    while (true) {
        auto current_result = _pattern->match(suffix);
        if (!current_result->success()) {
            break;
        }
        result = std::move(current_result);
        suffix = result->suffix();
    }
    return std::move(result);
}
