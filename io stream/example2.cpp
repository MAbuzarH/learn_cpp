#include <iostream>
#include <iomanip>

int main()
{

    double num{123456789.987654321};
    double num1{1234.5678};
    double num2{1234.0};

    std::cout << "default----------------" << std::endl;
    std::cout << num << std::endl;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;

    std::cout << " set precesion(2)----------------" << std::endl;
    std::cout << std::setprecision(2);
    std::cout << num << std::endl;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;

    std::cout << " set precesion(5)----------------" << std::endl;
    std::cout << std::setprecision(5);
    std::cout << num << std::endl;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;

    std::cout << " set precesion(9)----------------" << std::endl;
    std::cout << std::setprecision(9);
    std::cout << num << std::endl;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;

    std::cout << " set precesion(3)------fixed----------" << std::endl;
    std::cout << std::setprecision(3) << std::fixed;
    std::cout << num << std::endl;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;

    std::cout << " set precesion(3)------scientific----------" << std::endl;
    std::cout << std::setprecision(3) << std::scientific;
    std::cout << num << std::endl;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;

    std::cout << " set precesion(3)------scientific---uppercas-------" << std::endl;
    std::cout << std::setprecision(3) << std::scientific << std::uppercase;
    std::cout << num << std::endl;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;

    std::cout << " set precesion(3)------fixed----showpos------" << std::endl;
    std::cout << std::setprecision(3) << std::fixed << std::showpos;
    std::cout << num << std::endl;
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;

    std::cout.unsetf(std::ios::scientific | std::ios::fixed);
    std::cout << std::setiosflags(std::ios::showpos);

    

    return 0;
}