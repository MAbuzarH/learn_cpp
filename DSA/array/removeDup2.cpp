#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr{1, 1, 1, 2, 2, 2, 3, 3, 3};
    int i = 0;
    int n = arr.size();
    for (int j = 1; j < n; j++)
    {
        if (arr[j] != arr[i])
        {
            arr[i + 1] = arr[j];
            cout << "in if \n";
            i++;
        }
    }

    // cout << i;
    for (int k = 0; k <= i; k++)
    {
        cout << arr[k] << " ";
    }

    return 0;
}