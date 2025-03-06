#include <iostream>
using namespace std;
double e(int x, int n)
{
    static double s = 1;
    if (n == 0)
        return s;
    else
        s = 1 + x * s / n;
    return e(x, n - 1);
}

int main()
{
    int x = 2;
    int n = 10;
    cout << e(x, n) << endl;
}