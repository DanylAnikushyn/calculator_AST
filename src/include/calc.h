#ifndef CALC_H
#define CALC_H
#include <string>

// compiling from expression 
void calc_compile(std::string& src);
// compiling from filename
void calc_compile_file(const char* filename);
#endif