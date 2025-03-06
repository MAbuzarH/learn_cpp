#include <iostream>
using namespace std;
int x = 0;
int fun(int j)
{
    if (j > 0)
    {
        x++;
        cout << "before" << x << " ";
        return fun(j - 1) + x;
        
    }
    return 0;
}
int main()
{
    int k = 5;
    cout << x << endl;
    cout << fun(k) << endl;
    cout << x << endl;
    return 0;
}