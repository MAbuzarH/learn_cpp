#include <iostream>
#include <fstream>

int main()
{
    std::ifstream in_file;
    in_file.open("poem.txt");
    if (!in_file)
    {
        std::cout << "Error: Could not open" << std::endl;
    }
    else
    {
        std::string line;
        while (std::getline(in_file, line))
        {
            std::cout << line << std::endl;
        }
    }
      in_file.close();
    return 0;
}