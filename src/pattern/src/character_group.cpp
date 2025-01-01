#include "character_group.h"
#include "match_result.h"

regex::character_group::character_group(const std::string& reference, const bool& exclude)
    : _reference(reference), _exclude(exclude)
{
}


std::unique_ptr<regex::imatch_result> regex::character_group::match(const std::string& target) const
{
    bool matched = false;
    size_t matched_index = 0;

    if (!target.empty()) {
        matched_index = _reference.find(target.at(0));
        matched = (_reference.find(target.at(0)) != std::string::npos);
    }

    matched = matched == _exclude ? false : true;

    if (!matched) {
        return std::make_unique<match_result>(false, std::string(), target);
    }

    return std::make_unique<match_result>(true, std::string(), target.substr(1, target.size()));
}
