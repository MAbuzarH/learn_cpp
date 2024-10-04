#include <bits/stdc++.h>
using namespace std;
int main()
{
    int s = 5;
    int arr[s] = {1, 2, 3, 4, 5};
    int temp = arr[0];
    for (int i = 1; i < s; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[s - 1] = temp;
    for (int j = 0; j < s; j++)
    {
        cout << arr[j] << "";
    }

    return 0;
}