#ifndef REGEX_IPATTERN_H
#define REGEX_IPATTERN_H

#include <memory>
#include <string>

#include "interface.h"

namespace regex
{
    class imatch_result;

    class ipattern
    {
        INTERFACE(ipattern);

    public:
        virtual std::unique_ptr<imatch_result> match(const std::string& target) const = 0;

    protected:
        ipattern() = default;
    };

    inline ipattern::~ipattern() = default;
}


#endif // REGEX_IPATTERN_H