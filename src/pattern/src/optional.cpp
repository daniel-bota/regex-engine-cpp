#include "optional.h"
#include "match_result.h"

regex::optional::optional(std::unique_ptr<ipattern> pattern)
    : _pattern(std::move(pattern))
{
}


std::unique_ptr<regex::imatch_result>
    regex::optional::match(const std::string& target) const
{
    std::unique_ptr<imatch_result> result =
        std::make_unique<match_result>(true, std::string(), target);

    auto pattern_match_result = _pattern->match(target);
    if (!pattern_match_result->success())
    {
        return std::make_unique<match_result>(true, std::string(), target);
    }
    return std::move(pattern_match_result);
}
