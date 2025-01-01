#ifndef REGEX_WILDCARD_H
#define REGEX_WILDCARD_H

#include "ipattern.h"

namespace regex
{
    class wildcard : public ipattern
    {
    public:
        wildcard() = default;
        std::unique_ptr<imatch_result> match(const std::string& target) const override;

    private:
    };
}

#endif