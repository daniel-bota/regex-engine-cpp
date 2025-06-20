#ifndef _REGEX_PARSER_I_QUANTIFIER_H
#define _REGEX_PARSER_I_QUANTIFIER_H

#include "framework/macros.h"
#include "parser/interface/i_token.h"

#include <memory>
#include <string>
#include <utility>

namespace regex::parser
{
    class i_quantifier : public i_token
    {
        INTERFACE(i_quantifier)
    public:
        // virtual quantifier_range get_range() const = 0;


    protected:
    };
}

#endif //_REGEX_PARSER_I_QUANTIFIER_H