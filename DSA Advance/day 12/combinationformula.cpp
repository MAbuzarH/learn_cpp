// finding ncr using recursion
// first we have to understand pasical triangle
//  ncr 2c1 = 1c0 +1c1
// ncr 2c2 = ((n-1)c(r-1)) + ((n-1) c r)
#include <iostream>
using namespace std;
int C(int n, int r)
{
    if (r == 0 || n == r)
        return 1;
    else
        return C(n - 1, r - 1) + C(n - 1, r);
}
int main()
{
    int n = 4, r = 2;
    cout << C(n, r);
    return 0;
}