#ifndef REGEX_ONE_OR_MORE_H
#define REGEX_ONE_OR_MORE_H

#include "ipattern.h"

#include <memory>

namespace regex
{
    class one_or_more : public ipattern
    {
    public:
        one_or_more(std::unique_ptr<ipattern> pattern);
        std::unique_ptr<imatch_result>
            match(const std::string& target) const override;

    private:
        std::unique_ptr<ipattern> _pattern;
    };
}

#endif // REGEX_ONE_OR_MORE_H