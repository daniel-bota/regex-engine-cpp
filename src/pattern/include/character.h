#ifndef REGEX_CHARACTER_H
#define REGEX_CHARACTER_H

#include "ipattern.h"

namespace regex
{
    class imatch_result;

    class character : public ipattern
    {
    public:
        character(const char& ch);
        std::unique_ptr<imatch_result> match(const std::string& target) const override;

    private:
        char _character;
    };
}

#endif // REGEX_CHARACTER_H