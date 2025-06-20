#include "pattern_parser.h"

#include "alpha.h"
#include "character_group.h"
#include "character.h"
#include "choice.h"
#include "digit.h"
#include "isequence.h"
#include "one_or_more.h"
#include "sequence.h"
#include "optional.h"
#include "wildcard.h"

#include <functional>
#include <iostream>


regex::pattern_parser::~pattern_parser()
{
}


std::unique_ptr<regex::ipattern>
    regex::pattern_parser::parse(const std::string& pattern) const
{
    std::cout << "Parsing pattern: " << pattern << '\n';
    auto sequence = std::make_unique<regex::sequence>();

    anchors anchor_flags;
    size_t next_index_to_parse = 0;
    for (size_t i = 0; i < pattern.size(); ++i) {
        if (i < next_index_to_parse) {
            continue;
        }
        parse_pattern_at_index(
            pattern, i, next_index_to_parse, *sequence, anchor_flags);
    }

    sequence->set_start_of_string_anchor(anchor_flags.start_of_string);
    sequence->set_end_of_string_anchor(anchor_flags.end_of_string);
    return std::move(sequence);
}


void regex::pattern_parser::parse_pattern_at_index(const std::string& pattern,
                                                   size_t index,
                                                   size_t& next_index_to_parse,
                                                   isequence& sequence,
                                                   anchors& anchor_flags) const
{
    constexpr char START_ANCHOR = '^';
    constexpr char END_ANCHOR = '$';
    constexpr char CHAR_CLASS_TOKEN = '\\';
    constexpr char CHAR_GROUP_TOKEN = '[';
    constexpr char ONE_OR_MORE_TOKEN = '+';
    constexpr char OPTIONAL_TOKEN = '?';
    constexpr char WILDCARD = '.';

    switch (pattern.at(index))
    {
    case START_ANCHOR: {
        if (index != 0) {
            throw std::runtime_error("Regex expression malformed: " + pattern +
                                     " at index " + std::to_string(index));
        }
        anchor_flags.start_of_string = true;
        break;
    }
    case END_ANCHOR: {
        if (index != pattern.size() - 1) {
            throw std::runtime_error("Regex expression malformed: " + pattern +
                                     " at index " + std::to_string(index));
        }
        anchor_flags.end_of_string = true;
        break;
    }
    case CHAR_CLASS_TOKEN: {
        const size_t char_class_index = index + 1;
        next_index_to_parse = char_class_index + 1;
        sequence.add(
            std::move(parse_character_class(pattern.at(char_class_index))));
        break;
    }
    case CHAR_GROUP_TOKEN: {
        const size_t end_of_group = pattern.find(']', index);
        if (end_of_group == std::string::npos) {
            throw std::runtime_error("Character group malformed: " + pattern +
                                     " at index " + std::to_string(index));
        }
        next_index_to_parse = end_of_group + 1;
        sequence.add(std::move(parse_character_group(
            pattern.substr(index + 1, end_of_group - (index + 1)))));
        break;
    }
    case ONE_OR_MORE_TOKEN: {
        auto last_pattern = sequence.pop_back();
        auto new_pattern =
            std::make_unique<one_or_more>(std::move(last_pattern));
        sequence.add(std::move(new_pattern));
        break;
    }
    case OPTIONAL_TOKEN: {
        auto last_pattern = sequence.pop_back();
        auto new_pattern = std::make_unique<optional>(std::move(last_pattern));
        sequence.add(std::move(new_pattern));
        break;
    }
    case WILDCARD: {
        sequence.add(std::make_unique<wildcard>());
        break;
    }
    default: {
        std::cout << "Adding character to sequence: " << pattern.at(index)
                  << '\n';
        sequence.add(
            std::move(std::make_unique<regex::character>(pattern.at(index))));
    }
    }
}


std::unique_ptr<regex::ipattern>
    regex::pattern_parser::parse_character_class(const char& ch) const
{
    std::cout << "Parsing character class: " << ch << '\n';

    switch (ch) {
    case 'd':
        return std::make_unique<regex::digit>();
    case 'w': {
        auto choice = std::make_unique<regex::choice>();
        choice->add(std::make_unique<regex::alpha>());
        choice->add(std::make_unique<regex::digit>());
        return std::move(choice);
    }
    default:
        throw std::runtime_error("Unhandled character class: \\" + ch);
    }
}


std::unique_ptr<regex::ipattern> regex::pattern_parser::parse_character_group(
    const std::string& pattern) const
{
    std::cout << "Parsing character group: " << pattern << '\n';

    bool exclude = pattern.at(0) == '^';
    size_t index = exclude ? 1 : 0;

    return std::make_unique<character_group>(pattern.substr(index, pattern.size()),
                                 exclude);
}
