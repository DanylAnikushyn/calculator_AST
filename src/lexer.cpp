#include "include/lexer.h"
#include <iostream>

Lexer::Lexer(std::string source)
{
    src = source;
    size = src.length();
    i = 0;
    c = src[i];
}

void Lexer::advance()
{
    if (i < size) 
    {
        ++i;
        c = src[i];
    }
}

Token* Lexer::advance_current(TOKEN_TYPE type) 
{
    std::string value;
    value += c;

    Token* token = new Token(value, type);
    advance();

    return token;
}

void Lexer::skip_whitespaces() 
{
    while (c == ' ' || c == '\t' || c == 10 || c == 13)
        advance();
}

Token* Lexer::parse_number()
{
    std::string value;

    while (isdigit(c))
    {
        value += c;
        advance();
    }

    return new Token(value, TOKEN_INT);
}

Token* Lexer::next_token()
{
    while (c != '\0')
    {
        //std::cout << i << std::endl;
        skip_whitespaces();

        if (isdigit(c)) 
            return parse_number();

        switch(c)
        {
            case '(': return advance_current(TOKEN_LPA);
            case ')': return advance_current(TOKEN_RPA);
            case '+': return advance_current(TOKEN_ADD);
            case '-': return advance_current(TOKEN_SUB);
            case '*': return advance_current(TOKEN_MUL);
            case '/': return advance_current(TOKEN_DIV);
            case '\0': break;
            default: std::cerr << "(Lexer :: Unexpected character " << c << std::endl; exit(1); break;
        } 
    }
    return new Token("", TOKEN_EOF);
}