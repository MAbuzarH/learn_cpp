#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>

int main()
{
    std::string name{};
    int age{};
    double salary{};
    std::string info{"moe 20 123.4"};
    std::istringstream iss(info);
    iss >> name >> age >> salary;
    std::cout << name << " " << age << " " << salary << std::endl;
    std::cout << " \n----------------------\n";

    std::ostringstream oss{};

    oss << std::setw(10) << std::left << name << std::setw(10) << std::left << age << std::setw(10) << std::left << salary << std::endl;
    std::cout << oss.str() << std::endl;

    std::cout << " \n---------veladition-------------\n";

    int value{};
    std::string entry;
    bool done = false;
    do
    {
        std::cout << "Enter a value" << std::endl;
        std::cin >> entry;
        std::istringstream ss{entry};
        if (ss >> value)
        {
            done = true;
        }
        else
        {
            std::cout << "Enter an integer" << std::endl;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (!done);

    std::cout << " you enter an integer 😀 \n";
    return 0;
}