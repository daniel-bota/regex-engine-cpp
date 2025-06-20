#include "sequence.h"
#include "match_result.h"


regex::sequence::~sequence()
{
}


size_t regex::sequence::size() const 
{
    return _patterns.size();
}


void regex::sequence::add(std::unique_ptr<ipattern> pattern)
{
    if (!pattern)
        return;

    _patterns.push_back(std::move(pattern));
}


void regex::sequence::remove_at(const size_t& index) 
{
    _patterns.erase(_patterns.begin() + index);
}


std::unique_ptr<regex::ipattern> regex::sequence::pop_back()
{
    std::unique_ptr<ipattern> pattern = std::move(_patterns.at(_patterns.size() - 1));
    remove_at(_patterns.size() - 1);
    return std::move(pattern);
}


std::unique_ptr<regex::imatch_result> regex::sequence::match(const std::string& target) const
{
    if (target.empty())
        return std::make_unique<regex::match_result>(false, std::string(), target);

    if (_start_of_string_anchor) {
        return match_start_of_string(target);
    }

    for (size_t i = 0; i < target.size(); ++i) {
        auto result = match_start_of_string(target.substr(i, target.size()));
        if (result->success()) {
            return std::move(result);
        }
    }

    return std::make_unique<match_result>(false, std::string(), target);
}


void regex::sequence::set_start_of_string_anchor(const bool& value)
{
    _start_of_string_anchor = value;
}


void regex::sequence::set_end_of_string_anchor(const bool& value)
{
    _end_of_string_anchor = value;
}


std::unique_ptr<regex::imatch_result> regex::sequence::match_start_of_string(const std::string& target) const
{
    std::string suffix = target;
    for (const std::unique_ptr<ipattern>& pattern : _patterns) {
        auto pattern_match = pattern->match(suffix);
        if (!pattern_match->success()) {
            return std::make_unique<regex::match_result>(false, std::string(), target);
        }
        suffix = pattern_match->suffix();
    }

    if (_end_of_string_anchor && !suffix.empty()) {
        return std::make_unique<regex::match_result>(false, std::string(), target);
    }
    return std::make_unique<regex::match_result>(true, std::string(), suffix);
}
