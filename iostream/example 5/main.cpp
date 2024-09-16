#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

int main()
{
    std::ofstream out_file;
    out_file.open("output.txt", std::ios::app);

    std::string line;
    std::cout << "Enter to write on file" << std::endl;
    std::getline(std::cin, line);
    if (!out_file)
    {
        std::cerr << "Error: Could not open output file" << std::endl;
        return 1;
    }
    out_file << line << std::endl;

    out_file.close();
    return 0;
}