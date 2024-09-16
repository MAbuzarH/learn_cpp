#include <iostream>
#include <fstream>
#include <iomanip>

int main()
{
    std::ifstream in_file;
    in_file.open("copy.txt");
    std::ofstream out_file;
    out_file.open("mytext.txt");

    if (!in_file)
    {
        std::cerr << "Error: Could not open" << std::endl;
        return 1;
    }
    if (!out_file)
    {
        std::cerr << "Error: Could not open" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(in_file, line))
    {
        out_file << std::setw(70) << line << std::endl;
    }

    in_file.close();
    out_file.close();
    return 0;
}