#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s = 5;
    int arr[s] = {56, 43, 22, 1, 56};
    int large = arr[0];
    int secLarge = -1;

    for (int i = 0; i < s; i++)
    {
        if (arr[i] > large)
        {
            secLarge = large;
            large = arr[i];
        }
        else if (arr[i] < large && arr[i] > secLarge)
        {
            secLarge = arr[i];
        }
    }

    cout << "Large: " << large << endl;
    cout << "seconds: " << secLarge << endl;
    return 0;
}