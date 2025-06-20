#include "compiler/nfa.h"
#include "compiler/state.h"

#include "framework/macros.h"

NAMESPACE_BEGIN(regex::compiler)


std::unique_ptr<i_state> nfa::create_state()
{
    return std::unique_ptr<state>();
}

std::unique_ptr<i_transition> nfa::create_transition()
{
    // return std::unique_ptr<transition>();
}


NAMESPACE_END(regex::compiler)
