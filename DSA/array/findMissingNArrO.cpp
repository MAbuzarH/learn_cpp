#include <bits/stdc++.h>
using namespace std;

int main()
{
    //better approch
    vector<int> arr{1, 2, 4, 5};
    int n = arr.size() + 1;
    vector<int> hash(6, 0);

    for (int i = 0; i < n - 1; i++)
    {
        hash[arr[i]] = 1;
    }
    for (int j = 1; j < n + 1; j++)
    {
        // cout << hash[j] << endl;
        if (hash[j] == 0)
        {
            cout << j << endl;
            break;
        }
    }

    return 0;
}