#include <bits/stdc++.h>
using namespace std;
// brote force approch;
int main()
{

    bool result;
    vector<int> arr{2, 3, 4, 5};
    // vector<int> res(5, 0);
    int n = 5;
    int i = 1;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << res[i] << endl;
    // }
    for (; i <= n; i++)
    {
        result = 0;
        for (int k = 0; k < n - 1; k++)
        {
            // cout << (j == arr[k]);
            if (i == arr[k])
            {
                result = 1;
                break;
            }
        }
        if (result == 0)
        {
            cout << "not in arr: " << i << endl;
        }
    }

    return 0;
}