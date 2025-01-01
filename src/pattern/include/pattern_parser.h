#ifndef REGEX_PATTERN_PARSER_H
#define REGEX_PATTERN_PARSER_H

#include "ipattern_parser.h"

namespace regex
{
    class ipattern;
    class isequence;
    struct anchors;

    class pattern_parser : public ipattern_parser
    {
    public:
        pattern_parser() = default;
        // rule of five
        pattern_parser(const pattern_parser& other) = delete;
        pattern_parser(const pattern_parser&& other) = delete;
        ~pattern_parser();
        pattern_parser& operator=(const pattern_parser& other) = delete;
        pattern_parser& operator=(const pattern_parser&& other) = delete;
        std::unique_ptr<ipattern>
            parse(const std::string& pattern) const override;

    private:
        void parse_pattern_at_index(
            const std::string& pattern,
            size_t index,
            size_t& next_index_to_parse,
            isequence& sequence,
            anchors& anchor_flags) const;
        std::unique_ptr<ipattern> parse_character_class(const char& ch) const;
        std::unique_ptr<ipattern>
            parse_character_group(const std::string& pattern) const;
    };
}

#endif // REGEX_PATTERN_PARSER_H