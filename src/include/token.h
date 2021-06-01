#ifndef CALC_TOKEN_H
#define CALC_TOKEN_H
#include <string>

enum TOKEN_TYPE {
    TOKEN_INT = 1,
    TOKEN_ADD,
    TOKEN_SUB,
    TOKEN_MUL,
    TOKEN_DIV,
    TOKEN_LPA,
    TOKEN_RPA,
    TOKEN_EOF
};

std::string token_type(TOKEN_TYPE type);

struct Token {
    std::string value;
    TOKEN_TYPE type;
    Token(std::string value, TOKEN_TYPE type);
};
#endif