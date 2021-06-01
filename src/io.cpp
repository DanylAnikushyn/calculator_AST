#include "include/io.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

bool calc_read_file(const char* filename, std::string& buffer)
{
    if (!filename) 
    {
        std::cerr << "Please specify filename" << std::endl;
        return false;
    }
    std::ifstream in(filename);

    if (!in)
    {
        std::cerr << "Cannot open the file: " << filename << std::endl;
        return false;
    }

    std::string str;
    while (std::getline(in, str))
    {
        if (str.size() > 0) 
            buffer += str;
    }
    in.close();
    return true;
}