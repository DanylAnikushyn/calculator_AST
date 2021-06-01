#ifndef CALC_AST_H
#define CALC_AST_H
#include <vector>
#include <string>
#include "token.h"

enum AST_TYPE 
{
    AST_COMPOUND = 1,
    AST_INT,                  // integer          
    AST_BINOP                 // binary operation
};

class AST
{
public:
    AST_TYPE type;
    AST* value;
    AST* left;
    AST* right;
    TOKEN_TYPE op;
    int int_value;

    AST(AST_TYPE type);
    ~AST();
};

std::string ast_type(AST_TYPE type);
void print(AST* ast);
// calculating AST branch
int calculate(AST* ast);

#endif
