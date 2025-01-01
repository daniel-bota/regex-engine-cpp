#ifndef REGEX_ALPHA_H
#define REGEX_ALPHA_H

#include "ipattern.h"

namespace regex
{
    class alpha : public ipattern
    {
    public:
        std::unique_ptr<imatch_result> match(const std::string& target) const override;

    private:
    };
}

#endif // REGEX_ALPHA_H