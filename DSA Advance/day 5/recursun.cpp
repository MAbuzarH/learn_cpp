// loop vs rcurisun loop has assending phase but
// recursun has both assending phase and decending phase
//  1 assending phase
//  2 recursive call
//  2 decending phase

#include <stdio.h>
#include <iostream>
using namespace std;
void fun1(int n)
{
    if (n > 0)
    {
        //assending phase
        //calling time
        printf("N before call : %d\n", n);
        fun1(n - 1);
        //decending phase
        //returning time
        printf("N after call : %d\n", n);
    }
}

int main()
{
    int n = 3;
    fun1(n);
    return 0;
}