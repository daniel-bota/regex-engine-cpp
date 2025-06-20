#ifndef REGEX_MATCH_RESULT_H
#define REGEX_MATCH_RESULT_H

#include "imatch_result.h"

namespace regex
{
    class match_result : public imatch_result
    {
    public:
        match_result(bool success, const std::string& prefix, const std::string& suffix);
        bool success() const override;
        const std::string& prefix() const override;
        const std::string& suffix() const override;

    private:
        bool _success;
        std::string _prefix;
        std::string _suffix;
    };
}

#endif // REGEX_MATCH_RESULT_H