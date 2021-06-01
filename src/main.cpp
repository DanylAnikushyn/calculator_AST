#include <iostream>
#include "include/calc.h"

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Please specify input file" << std::endl;
        return 1;
    }
    calc_compile_file(argv[1]);
    return 0;
}