#include <iostream>
using namespace std;
// talor sereas e^x = 1+(x/1)+(x^2/2!)+(x^3/3!)
// sum(n-1)+n
// fac(n-1)*n
// pow(m,n-1)*m
// if odd
// m * pow(m * m, (n-1) / 2)
double e(int x, int n)
{
    static double p = 1, f = 1;
    double r;
    if (n == 0)
        return 1;
    else
    {
        r = e(x, n - 1);
        p = p * x;
        f = f * n;
        return r + p / f;
    }
}
int main()
{
    int x = 1;
    int n = 10;

    cout << e(x, n);
}