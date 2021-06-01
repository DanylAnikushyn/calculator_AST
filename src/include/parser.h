#ifndef CALC_PARSER_H
#define CALC_PARSER_H
#include "lexer.h"
#include "ast.h"

class Parser
{
public:
    Parser(Lexer* lexer);
    ~Parser();

    AST* parse();
private: 
    Lexer* lexer;
    Token* token;
    // to next token
    void eat(TOKEN_TYPE type);
    // parsing parentheses
    AST* parse_paren();
    // parsing int
    AST* parse_int();
    // parsing parts of expression with different priorities
    // high priority - number or parentheses
    // middle priority - mul / div operations
    // low priority - add / sub operations
    AST* parse_high_prior();
    AST* parse_middle_prior();
    AST* parse_low_prior();
    // parsing whole expressions or subexpression in parentheses
    AST* parse_compound();
};

#endif