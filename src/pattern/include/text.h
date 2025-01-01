#ifndef REGEX_TEXT_H
#define REGEX_TEXT_H

#include "ipattern.h"

namespace regex
{
    class text : public ipattern
    {
    public:
        text(const std::string& reference);
        std::unique_ptr<imatch_result> match(const std::string& target) const override;

    private:
        std::string _reference;
    };
}

#endif // REGEX_TEXT_H