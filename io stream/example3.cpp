#include <iostream>
#include <iomanip>

void ruler()
{
    std::cout << std::endl
              << "1234567890123456789012345678901234567890 \n"
              << std::endl;
}

int main()
{
    int num1{1234};
    double num2{1234.56};
    std::string hello{"Hello"};

    std::cout << "default-------------------------------- \n";
    ruler();
    std::cout << num1 << num2 << hello << std::endl;

    std::cout << "default---one pr line------------------ \n";
    ruler();
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    std::cout << hello << std::endl;

    std::cout << "width(10) num-------------------------------- \n";
    ruler();
    std::cout << std::setw(10) << num1 << num2 << hello << std::endl;

    std::cout << "width(10) num1,2 ---------------------------- \n";
    ruler();
    std::cout << std::setw(10) << num1
              << std::setw(10) << num2 << hello << std::endl;

    std::cout << "width(10) num1,2,Hel ---------------------------- \n";
    ruler();
    std::cout << std::setw(10) << num1
              << std::setw(10) << num2 << std::setw(10) << hello << std::endl;

    std::cout << "width(10) num1,2,Hel left ALL ---------------------------- \n";
    ruler();
    std::cout << std::setw(10) << std::left << num1
              << std::setw(10) << std::left << num2
              << std::setw(10) << std::left << hello
              << std::endl;

    // spaces with -
    std::cout << std::setfill('-');
    std::cout << "width(10) num1,2,Hel left ALL setfil ---------------------------- \n";
    ruler();
    std::cout << std::setw(10) << std::left << num1
              << std::setw(10) << std::left << num2
              << std::setw(10) << std::left << hello
              << std::endl;

    std::cout << "width(10) num1,2,Hel left ALL set fillall---------------------- \n";
    ruler();
    std::cout << std::setw(10) << std::left << std::setfill('*') << num1
              << std::setw(10) << std::left << std::setfill('-') << num2
              << std::setw(10) << std::left << std::setfill('#') << hello
              << std::endl;
    return 0;
}

// std::cout << std::setw(10) << std::right << a << std::setw(10) << std::right << hello
//           << std::setw(15) << std::right << hello
//           << std::endl;