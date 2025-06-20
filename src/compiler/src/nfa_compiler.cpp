#include "compiler/nfa_compiler.h"

#include "compiler/nfa.h"
#include "framework/macros.h"
#include "parser/basic_parser.h"
#include "parser/lexer.h"

NAMESPACE_BEGIN(regex::compiler)


void nfa_compiler::initialize_nfa()
{
    _nfa = std::make_unique<nfa>();
}


void nfa_compiler::compile(const parser::i_token_ast& ast)
{
}


void nfa_compiler::compile(const std::string& regex)
{
    using namespace regex::parser;
    basic_parser parser(std::make_unique<lexer>());
    parser.compute(regex);
    compile(parser.get_syntax_tree());
}


NAMESPACE_END(regex::compiler)