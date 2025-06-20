#ifndef _REGEX_COMPILER_STATE_H
#define _REGEX_COMPILER_STATE_H

#include "compiler/interface/i_state.h"

#include <vector>

namespace regex::compiler
{
    class state : public i_state
    {
        public:
        protected:
        private:
            std::vector<std::unique_ptr<i_transition>> _transitions;
    };
}

#endif // _REGEX_COMPILER_STATE_H