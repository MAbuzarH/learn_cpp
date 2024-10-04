#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s1 = 4;
    int s2 = 6;
    int arr1[s1] = {1, 2, 3, 4};
    int arr2[s2] = {1, 2, 5, 6, 7, 9};
    set<int> mySet;
    for (int i = 0; i < s1; i++)
    {
        mySet.insert(arr1[i]);
    }
    for (int j = 0; j < s2; j++)
    {
        mySet.insert(arr2[j]);
    }
    auto it = mySet.begin();
    while (it != mySet.end())
    {
        cout << *it << " ";
        it++;
    }
    return 0;
}