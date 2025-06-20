#ifndef REGEX_CHOICE_H
#define REGEX_CHOICE_H

#include "ipattern.h"

#include <vector>

namespace regex
{
    class choice : public ipattern
    {
    public:
        choice() = default;
        // rule of five
        choice(const choice& other) = delete;
        choice(const choice&& other) = delete;
        ~choice();
        choice& operator=(const choice& other) = delete;
        choice& operator=(const choice&& other) = delete;

        void add(std::unique_ptr<ipattern> pattern);
        std::unique_ptr<imatch_result> match(const std::string& target) const override;

    private:
        std::vector<std::unique_ptr<ipattern>> _patterns;
    };
}

#endif // REGEX_CHOICE_H