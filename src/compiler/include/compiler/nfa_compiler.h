#ifndef _REGEX_COMPILER_NFA_COMPILER_H
#define _REGEX_COMPILER_NFA_COMPILER_H

#include <memory>
#include <string>

namespace regex
{
    namespace parser
    {
        class i_token_ast;
    }

    namespace compiler
    {
        class i_nfa;
    }
}

namespace regex::compiler
{
    class nfa_compiler
    {
    public:
        void compile(const std::string& regex);

    private:
        std::unique_ptr<i_nfa> _nfa;

        void initialize_nfa();
        void compile(const parser::i_token_ast&);
    };
}

#endif // _REGEX_COMPILER_NFA_COMPILER_H