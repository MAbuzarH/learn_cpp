#include <iostream>
#include <iomanip>

int main()
{
    // default case
    std::cout << "noalpha default (10==10) : " << (10 == 10) << std::endl;
    std::cout << "noalpha default (10==10) : " << (10 == 20) << std::endl;

    // seting boolalpha
    std::cout << std::boolalpha;
    std::cout << "boolalpha  (10==10) : " << (10 == 10) << std::endl;
    std::cout << "bollalpha  (10==10) : " << (10 == 20) << std::endl;

    // seting noboolalpha
    std::cout << std::noboolalpha;
    std::cout << "noboolalpha  (10==10) : " << (10 == 10) << std::endl;
    std::cout << "nobollalpha  (10==10) : " << (10 == 20) << std::endl;

    // seting back true/false
    std::cout.setf(std::ios::boolalpha);
    std::cout << "boolalpha  (10==10) : " << (10 == 10) << std::endl;
    std::cout << "bollalpha  (10==10) : " << (10 == 20) << std::endl;

    // reset ios boolplagh
    std::cout << std::resetiosflags(std::ios::boolalpha);
    std::cout << "reset ios flags  (10==10) : " << (10 == 10) << std::endl;
    std::cout << "reset ios flags (10==10) : " << (10 == 20) << std::endl;
    return 0;
}