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
        char c;
        while (in_file.get(c))
        {
            std::cout << c;
        }
        // std::cout << std::endl;
    }
    in_file.close();
    return 0;
}