#ifndef _REGEX_COMPILER_NFA_H
#define _REGEX_COMPILER_NFA_H

#include "compiler/interface/i_nfa.h"

#include <memory>
#include <unordered_set>
#include <unordered_map>

namespace regex::compiler
{
    class i_state;
    class i_transition;
}

namespace regex::compiler
{
    class nfa : public i_nfa
    {
    public:
        
    protected:
    private:
        i_state* _start_state;
        std::unordered_set<i_state*> _end_states;
        std::unordered_map<std::unique_ptr<i_state>,
                           std::unique_ptr<i_transition>>
            _transitions;

        std::unique_ptr<i_state> create_state();
        std::unique_ptr<i_transition> create_transition();
    };
}

#endif // _REGEX_COMPILER_NFA_H