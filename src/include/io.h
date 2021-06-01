#ifndef CALC_IO_H
#define CALC_IO_H
#include <string>

// reading file with calc expression and writing expression to buffer
bool calc_read_file(const char* filename, std::string& buffer);
#endif