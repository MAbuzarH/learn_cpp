// static and global variables in recursion
/*

*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

// int x=0; // same result as static
int fun(int n)
{
    // static int x = 0;
    if (n > 0)
    {
        // x++;
        return fun(n - 1) + n;
    }
    return 0;
}
int main()
{
    int j = 5;
    printf("%d", fun(j));
    return 0;
}