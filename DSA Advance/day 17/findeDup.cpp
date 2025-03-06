#include <iostream>
using namespace std;
int main()
{

    int sz = 11;
    int predup = 0;
    int arr[sz] = {6, 7, 8, 8, 9, 10, 13, 15, 15, 15, 19};
    for (int i = 0; i < sz; i++)
    {
        if (arr[i] == arr[i + 1] && arr[i] != predup)
        {
            cout << arr[i] << " ";
        }
        predup = arr[i];
    }
}