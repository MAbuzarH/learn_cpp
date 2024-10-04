#include <bits/stdc++.h>
//brot force approch
using namespace std;

int main()
{
    set<int> myset;
    int s = 10;
    int arr[s] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4};
    for (int i = 0; i < s; i++)
    {
        myset.insert(arr[i]);
    }

    auto j = myset.begin();
    int index = 0;
    while (j != myset.end())
    {
        // cout << *j << " ";
        arr[index] = *j;
        index++;
        j++;
    }
    for (int i = 0; i < index; i++)
    {
        cout << arr[i];
    }

    cout << "\n"
         << myset.size() << endl;
    return 0;
}