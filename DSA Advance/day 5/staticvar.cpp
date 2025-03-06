#include <iostream>
using namespace std;

int fun()
{
    static int x = 0;
    return ++x;
}
int main()
{
    int k = 0;
    k = fun();
    cout << k << endl;
    k = fun();
    cout << k << endl;
    k = fun();
    cout << k << endl;

    return 0;
}