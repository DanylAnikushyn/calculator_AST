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

int main(int argc, char* argv[]) 
{
    std::string buffer;
    if (calc_read_file(argv[1], buffer)) 
    {
        std::cout << buffer << std::endl;
    }
    buffer += '1';
    std::cout << isdigit(buffer[0]) << std::endl;
    return 0;
}