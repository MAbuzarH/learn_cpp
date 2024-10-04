#include <bits/stdc++.h>
using namespace std;
int main()
//brote force approch 
{
    vector<int> arr1{2, 3, 3, 4, 5, 6, 7};
    vector<int> arr2{1, 2, 3, 3, 4, 5, 7, 9, 12};
    int s1 = arr1.size();
    int s2 = arr2.size();
    // int i = 0;
    // int j = 0;
    vector<int> ans;
    int visit[s1] = {0};
    for (int i = 0; i < s1; i++)
    {
        for (int j = 0; j < s2; j++)
        {
            if (arr1[i] == arr2[j] && visit[j] == 0)
            {
                ans.push_back(arr1[i]);
                visit[j] = 1;
                break;
            }
            if (arr2[j] > arr1[i])
                break;
        }
    }

    for (int k = 0; k < ans.size(); k++)
    {
        cout << ans[k] << " ";
    }
    return 0;
}