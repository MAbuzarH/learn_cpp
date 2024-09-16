#include <iomanip>
#include <iostream>
#include <fstream>

int main()
{
    std::ifstream in_file;
    std::string input;
    int searched{0};
    int found = 0;
    in_file.open("source.txt");

    if (!in_file)
    {
        std::cout << "Error: Cannot open source \n";
        return 1;
    }
    std::cout << "Enter a Word \n";
    std::cin >> input;
    std::string word;
    bool looped = false;
    while (in_file >> word)
    {
        for (int i = 0; i < input.size(); i++)
        {
            if (input[i] == word[i])
            {
                looped = true;
            }
            else
            {
                looped = false;
            }
        }

        if (looped)
        {
            found += 1;
            std::cout << word << "  ";
        }
        searched += 1;
    }

    std::cout << " \n"
              << searched << "  Word were searched \n";
    std::cout << found << " times founded \n";
    in_file.close();
    return 0;
}

bool find_sub(std::string &input, std::string &word)
{
    std::size_t found = word.find(input);
    if (found == std::string::npos)
    {
        return false;
    }
    else
    {
        return true;
    }
}