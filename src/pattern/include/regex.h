#ifndef REGEX_REGEX_H
#define REGEX_REGEX_H

#include <memory>
#include <string>

#include "ipattern.h"

namespace regex
{
    class ipattern_parser;

    class regex : public ipattern
    {
    public:
        // rule of five
        regex(const regex& other) = delete;
        regex(const regex&& other) = delete;
        ~regex();
        regex& operator=(const regex& other) = delete;
        regex& operator=(const regex&& other) = delete;
        regex(const std::string& pattern);
        std::unique_ptr<imatch_result> match(const std::string& target) const override;

    private:
        std::unique_ptr<ipattern> _pattern;
        std::unique_ptr<ipattern_parser> _pattern_parser;
    };
}
#endif // REGEX_REGEX_H