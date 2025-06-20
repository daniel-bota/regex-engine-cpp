#ifndef REGEX_OPTIONAL_H
#define REGEX_OPTIONAL_H

#include "ipattern.h"

namespace regex
{
    class optional : public ipattern
    {
    public:
        optional(std::unique_ptr<ipattern> pattern);
        std::unique_ptr<imatch_result>
            match(const std::string& target) const override;

    private:
        std::unique_ptr<ipattern> _pattern;
    };
}

#endif // REGEX_OPTIONAL_H