#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

int main()
{
    std::ifstream in_file;
    std::ofstream out_file;

    in_file.open("myfile.txt");
    out_file.open("copy.txt");

    std::string line;
    int i = 1;
    while (std::getline(in_file, line))
    {
        if (line == " ")
        {
            out_file << std::endl;
        }

        else
        {
            out_file << std::setw(7) << std::left << i << line << std::endl;
            i++;
        }
    }

    std::cout << "copy complete." << std::endl;
    in_file.close();
    out_file.close();
    return 0;
}