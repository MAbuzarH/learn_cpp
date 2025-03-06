#include <iostream>
using namespace std;
double e(int x, int n)
{
    double s = 1;
    for (; n > 0; n--)
    {
        s = (1 + (x* s / n)) ;
    }
    return s;
}
int main()
{
    int x = 2;
    int n = 15;
    cout << e(x, n) << endl;
    return 0;
}