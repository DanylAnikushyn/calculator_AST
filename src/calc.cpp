#include "include/calc.h"
#include "include/lexer.h"
#include "include/parser.h"
#include "include/io.h"
#include <iostream>
#include <string>

void calc_compile(std::string& src)
{
    Lexer* lexer = new Lexer(src);
    Parser* parser = new Parser(lexer);
    AST* root = parser->parse();;
   // print(root->value);
    std::cout << calculate(root) << std::endl;
    
    delete root;
    delete parser;
    delete lexer;
}

void calc_compile_file(const char* filename) 
{
    std::string src;
    if(!calc_read_file(filename, src)) exit(1);
    calc_compile(src);
}
