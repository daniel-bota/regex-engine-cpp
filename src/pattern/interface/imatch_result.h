#ifndef REGEX_IMATCH_RESULT_H
#define REGEX_IMATCH_RESULT_H

#include "interface.h"
#include <string>

namespace regex
{
    class imatch_result
    {
        INTERFACE(imatch_result);

    public:
        virtual bool success() const = 0;
        virtual const std::string& prefix() const = 0;
        virtual const std::string& suffix() const = 0;

    protected:
        imatch_result() = default;
    };

    inline imatch_result::~imatch_result() = default;
}

#endif // REGEX_IMATCH_RESULT_H