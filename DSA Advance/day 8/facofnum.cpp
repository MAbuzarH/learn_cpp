#include <iostream>
using namespace std;
// 3!
// 112!3!
int fac(int n)
{
    if (n < 0)
    {
        return 0;
    }
    else if (n > 0)
    {
        return fac(n - 1) * n;
    }
    return 1;
}
int main()
{
    int x = -1;
    cout << fac(x);
    return 0;
}