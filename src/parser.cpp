#include "include/parser.h"
#include <iostream>

Parser::Parser(Lexer* lexer) : lexer(lexer)
{
    token = lexer->next_token();
}

Parser::~Parser()
{
  delete token;
}


void Parser::eat(TOKEN_TYPE type) 
{
    if (token->type != type)
    {
        std::cerr << "Parser (eat): Unexpected token: " << token->type << ", was expecting " << type << std::endl;
        exit(1);
    }
    delete token;
    token = lexer->next_token();
}

AST* Parser::parse() 
{
    return parse_compound();
}

AST* Parser::parse_paren()
{
  eat(TOKEN_LPA);
  AST* ast = new AST(AST_COMPOUND);
  if (token->type != TOKEN_RPA)
  {
    ast->value = parse_low_prior();
  }
  else
  {
    std::cerr << "Parser: empty parentheses" << std::endl;
    exit(1);
  }
  eat(TOKEN_RPA);
  return ast;
}

AST* Parser::parse_int()
{
    int int_value = std::stoi(token->value);
    eat(TOKEN_INT);
    AST* ast = new AST(AST_INT);
    ast->op = TOKEN_INT; 
    ast->int_value = int_value;
    return ast;
}

AST* Parser::parse_high_prior()
{
    switch (token->type)
    {
        case TOKEN_LPA: return parse_paren();
        case TOKEN_INT: return parse_int();
        default: {
            std::cerr << "Parser (parse_high_prior): Unexpected token " << token->type << std::endl;
            exit(1);
        }
    }
}

AST* Parser::parse_middle_prior()
{
  AST* ast_left = parse_high_prior();
  if (
      token->type == TOKEN_MUL ||
      token->type == TOKEN_DIV
  )
  {
    AST* ast_binop = new AST(AST_BINOP);
    ast_binop->left = ast_left;
    ast_binop->op = token->type;
    eat(token->type); 
    ast_binop->right = parse_middle_prior();
    return ast_binop;
  }  

  return ast_left;
}

AST* Parser::parse_low_prior()
{
  AST* ast_left = parse_middle_prior();
  if (
      token->type == TOKEN_ADD ||
      token->type == TOKEN_SUB
  )
  {
    AST* ast_binop = new AST(AST_BINOP);
    ast_binop->left = ast_left;
    ast_binop->op = token->type;
    eat(token->type);
    ast_binop->right = parse_low_prior();
    return ast_binop;
  }
  
  return ast_left;
}

AST* Parser::parse_compound()
{
    AST* compound = new AST(AST_COMPOUND);

    while (token->type != TOKEN_EOF)
    {
      compound->value = parse_low_prior();
    }

    return compound;
}