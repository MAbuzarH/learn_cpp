#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr1{2, 3, 3, 4, 5, 6, 7};
    vector<int> arr2{1, 2, 3, 3, 4, 5, 7, 9, 12};
    int s1 = arr1.size();
    int s2 = arr2.size();
    int i = 0;
    int j = 0;
    vector<int> ans;

    while (i < s1 && j < s2)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr2[j] < arr1[i])
        {
            j++;
        }
        else
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    for (int k = 0; k < ans.size(); k++)
    {
        cout << ans[k] << " ";
    }
    return 0;
}