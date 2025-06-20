#include <iostream>

#include "match_result.h"
#include "pattern_parser.h"
#include "regex.h"


regex::regex::~regex()
{
}


regex::regex::regex(const std::string& pattern)
{
    std::cout << "Creating regular expression...\n";
    _pattern_parser = std::make_unique<pattern_parser>();
    _pattern = _pattern_parser->parse(pattern);
}


std::unique_ptr<regex::imatch_result> regex::regex::match(const std::string& target) const
{
    return _pattern->match(target);
}
