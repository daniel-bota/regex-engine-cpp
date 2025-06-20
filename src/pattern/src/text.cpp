#include "text.h"
#include "match_result.h"


regex::text::text(const std::string& reference) : _reference(reference)
{
}


std::unique_ptr<regex::imatch_result> regex::text::match(const std::string& target) const
{
    if (target.find(_reference) == 0) {
        return std::make_unique<match_result>(
            true, std::string(), target.substr(_reference.size(), target.size()));
    }
    return std::make_unique<match_result>(false, std::string(), std::string());
}
