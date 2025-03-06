#include <iostream>
using namespace std;
int main()
{
    int sz = 11;
    int arr[sz] = {6, 7, 8, 9, 11, 12, 14, 15, 16, 18, 19, 20};
    int l = arr[0];
    int dif = l - 0;
    int h = arr[sz - 1];
    for (int i = 0; i < sz; i++)
    {
        if (arr[i] - i > dif)
        {
            cout << "Missing number: " << i + dif << endl;
            dif = arr[i] - i;
        }
    }
    return 0;
}