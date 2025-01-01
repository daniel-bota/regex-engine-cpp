#ifndef REGEX_DIGIT_H
#define REGEX_DIGIT_H

#include "ipattern.h"

namespace regex
{
    class digit : public ipattern
    {
    public:
        std::unique_ptr<imatch_result> match(const std::string& target) const override;

    private:
    };
}

#endif // REGEX_DIGIT_H