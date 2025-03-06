#include <iostream>
using namespace std;
int main()
{
    int sz = 11;
    int arr[sz] = {6, 7, 8, 9, 11, 12, 15, 16, 18, 19, 20, 21};
    int l = arr[0];
    int dif = l - 0;
    int h = arr[sz - 1];
    for (int i = 0; i < sz; i++)
    {
        if (arr[i] - i != dif)
        {
            while (arr[i] - i > dif)
            {
                cout << "Missing number: " << i + dif << endl;
                dif++;
            }
        }
    }
    return 0;
}