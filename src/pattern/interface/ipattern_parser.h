#ifndef REGEX_IPATTERN_PARSER_H
#define REGEX_IPATTERN_PARSER_H

#include "interface.h"
#include "ipattern.h"

namespace regex
{
    class ipattern_parser
    {
        INTERFACE(ipattern_parser);

    public:
        virtual std::unique_ptr<ipattern> parse(const std::string& pattern) const = 0;

    protected:
        ipattern_parser() = default;
    };

    inline ipattern_parser::~ipattern_parser() = default;
}

#endif // REGEX_IPATTERN_PARSER_H