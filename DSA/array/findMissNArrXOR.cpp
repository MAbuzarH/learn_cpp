#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num = 5;
    vector<int> arr{1, 3, 4, 5};
    int xor1 = 0;
    int xor2 = 0;
    for (int i = 0; i < num - 1; i++)
    {
        xor1 = xor1 ^ arr[i];
        xor2 = xor2 ^ (i + 1);
    }
    xor2 = xor2 ^ num;
    // we also save time complexity
    // for (int j = 1; j <= num; j++)
    // {
    //     xor2 = xor2 ^ j;
    // }
    cout << (xor1 ^ xor2);

    return 0;
}