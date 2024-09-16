#include <iomanip>
#include <iostream>

void num_converter(int num)
{
    std::cout << std::hex << num << std::endl;
    std::cout << std::dec << num << std::endl;
    std::cout << std::oct << num << std::endl;
}
int main()
{

    int num{255};
    std::cout << "------------- \n";
    std::cout << std::hex << num << std::endl;
    std::cout << std::dec << num << std::endl;
    std::cout << std::oct << num << std::endl;

    std::cout << "============= \n";
    std::cout << std::showbase;
    std::cout << std::hex << num << std::endl;
    std::cout << std::dec << num << std::endl;
    std::cout << std::oct << num << std::endl;

    std::cout << "============= \n";
    std::cout << std::uppercase;
    std::cout << std::hex << num << std::endl;
    std::cout << std::dec << num << std::endl;
    std::cout << std::oct << num << std::endl;

   int num2; 
    std::cout << "============= \n";
    std::cout << std::showpos;
    std::cout << std::hex << num2 << std::endl;

    return 0;
}