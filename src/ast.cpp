#include "include/ast.h"
#include <iostream>

std::string ast_type(AST_TYPE type) 
{
    switch(type) 
    {
        case AST_COMPOUND: return "AST_COMPOUND";
        case AST_INT: return "AST_INT";
        case AST_BINOP: return "AST_BINOP";
        default: return "ast type not specified"; 
    }
}

AST::AST(AST_TYPE type) : type(type)
{
    value = nullptr;
    left = nullptr;
    right = nullptr;
}

AST::~AST()
{
    delete value;
    delete left;
    delete right;
}

void print(AST* ast) 
{
    if (ast->op != 0)
    {
        std::cout << ast->op << " " << token_type(ast->op) << std::endl;
        std::cout << ast->type << " " << ast_type(ast->type) << std::endl;
        std::cout << "-----------------------" << std::endl;
    }
    if (ast->left != nullptr) print(ast->left);
    if (ast->value != nullptr) 
    {
        print(ast->value);
    }
    if (ast->right != nullptr) print(ast->right);
}

int calculate(AST* ast)
{
    if (ast->type == AST_COMPOUND) 
    {
        return calculate(ast->value);
    }
    if (ast->type == AST_INT) 
    {
        return ast->int_value;
    }
    switch (ast->op) 
    {
        case TOKEN_ADD: {
            if (ast->right != nullptr && 
                    ast->right->left != nullptr && ast->right->right != nullptr) 
            {
                if (ast->right->op == TOKEN_ADD)
                    return calculate(ast->left) + calculate(ast->right->left) + calculate(ast->right->right);
                if (ast->right->op == TOKEN_SUB)
                    return calculate(ast->left) + calculate(ast->right->left) - calculate(ast->right->right);       
            }
            return calculate(ast->left) + calculate(ast->right);
        }
        case TOKEN_SUB: {
            if (ast->right != nullptr && 
                    ast->right->left != nullptr && ast->right->right != nullptr) 
            {
                if (ast->right->op == TOKEN_ADD)
                    return calculate(ast->left) - calculate(ast->right->left) + calculate(ast->right->right);
                if (ast->right->op == TOKEN_SUB)
                    return calculate(ast->left) - calculate(ast->right->left) - calculate(ast->right->right);       
            }
            return calculate(ast->left) - calculate(ast->right);
        }
        case TOKEN_MUL: { 
            if (ast->right != nullptr && 
                    ast->right->left != nullptr && ast->right->right != nullptr) 
            {
                if (ast->right->op == TOKEN_MUL)
                    return calculate(ast->left) * calculate(ast->right->left) * calculate(ast->right->right);
                if (ast->right->op == TOKEN_DIV)
                    return calculate(ast->left) * calculate(ast->right->left) / calculate(ast->right->right);       
            }
            return calculate(ast->left) * calculate(ast->right);
        }
        case TOKEN_DIV: {
            if (ast->right != nullptr && 
                    ast->right->left != nullptr && ast->right->right != nullptr) 
            {
                if (ast->right->op == TOKEN_MUL)
                    return calculate(ast->left) / calculate(ast->right->left) * calculate(ast->right->right);
                if (ast->right->op == TOKEN_DIV)
                    return calculate(ast->left) / calculate(ast->right->left) / calculate(ast->right->right);       
            }
            return calculate(ast->left) / calculate(ast->right);
        }
        default: std::cerr << "error" << std::endl; exit(1);
    }
}