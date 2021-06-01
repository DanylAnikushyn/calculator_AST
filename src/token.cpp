#include "include/token.h"
#include <string>

std::string token_type(TOKEN_TYPE type) 
{
    switch(type)
    {
        case TOKEN_INT: return "TOKEN_INT";
        case TOKEN_ADD: return "TOKEN_ADD";
        case TOKEN_SUB: return "TOKEN_SUB";
        case TOKEN_MUL: return "TOKEN_MUL";
        case TOKEN_DIV: return "TOKEN_DIV";
        case TOKEN_LPA: return "TOKEN_LPA";
        case TOKEN_RPA: return "TOKEN_RPA";
        case TOKEN_EOF: return "TOKEN_EOF";
        default: return "not specified token";
    }
}

Token::Token(std::string value, TOKEN_TYPE type) : value(value), type(type)
{
}