#include <iostream>
using namespace std;
int fib(int n)
{
    if (n <= 1)
        return n;
    int tz = 0;
    int to = 1;
    int i = 0;
    int s;
    for (i = 2; i <= n; i++)
    {
        s = to + tz;
        tz = to;
        to = s;
    }
    return s;
}
int main()
{
    cout << fib(7) << endl;
    return 0;
}