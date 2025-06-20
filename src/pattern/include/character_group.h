#ifndef REGEX_CHARACTER_GROUP_H
#define REGEX_CHARACTER_GROUP_H

#include "ipattern.h"

namespace regex
{
    class character_group : public ipattern
    {
    public:
        character_group(const std::string& reference, const bool& exclude = false);
        std::unique_ptr<imatch_result> match(const std::string& target) const override;

    private:
        std::string _reference;
        bool _exclude;
    };
}

#endif // REGEX_CHARACTER_GROUP_H