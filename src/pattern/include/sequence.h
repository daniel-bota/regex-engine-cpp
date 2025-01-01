#ifndef REGEX_SEQUENCE_H
#define REGEX_SEQUENCE_H

#include "ipattern.h"
#include "isequence.h"
#include "match_result.h"

#include <vector>

namespace regex
{
    class imatch_result;

    struct anchors
    {
        bool start_of_string = false;
        bool end_of_string = false;
    };

    class sequence : public ipattern, public isequence
    {
    public:
        sequence() = default;
        // rule of five
        sequence(const sequence& other) = delete;
        sequence(const sequence&& other) = delete;
        ~sequence();
        sequence& operator=(const sequence& other) = delete;
        sequence& operator=(const sequence&& other) = delete;
        size_t size() const override;
        void add(std::unique_ptr<ipattern> pattern) override;
        void remove_at(const size_t& index) override;
        std::unique_ptr<ipattern> pop_back() override;
        std::unique_ptr<imatch_result>
            match(const std::string& target) const override;
        void set_start_of_string_anchor(const bool& value);
        void set_end_of_string_anchor(const bool& value);

    private:
        std::vector<std::unique_ptr<ipattern>> _patterns{};
        bool _start_of_string_anchor = false;
        bool _end_of_string_anchor = false;

        std::unique_ptr<imatch_result>
            match_start_of_string(const std::string& target) const;
    };
}

#endif // REGEX_SEQUENCE_H