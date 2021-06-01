#ifndef CALC_LEXER_H
#define CALC_LEXER_H
#include "token.h"
#include <string>
class Lexer
{
public:
    Lexer(std::string src);
    
    Token* next_token();
private:
    // expression to parse from file
    std::string src;
    // size of expression to parse
    size_t size;
    // current symbol in src
    char c;
    // current index in src
    unsigned int i;

    // to next symbol
    void advance();
    Token* advance_current(TOKEN_TYPE type);

    void skip_whitespaces();

    Token* parse_number();
};
#endif