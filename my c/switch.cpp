#include <iostream>
#include <stdio.h>

int main() {
    char grade = 'C';
    
    switch (grade) {
        case 'A':
            std::cout << "EXCELLENT" << std::endl;
            break;
        case 'B':
            std::cout << "GOOD" << std::endl;
            break;
        case 'C':
            std::cout << "ACCEPTABLE" << std::endl;
            break;
        case 'D':
            std::cout << "POOR" << std::endl;
            break;
        case 'F':
            std::cout << "FAIL" << std::endl;
            break;
        default:
            std::cout << "Invalid grade" << std::endl;
            break;
    }
    
    return 0;
}
