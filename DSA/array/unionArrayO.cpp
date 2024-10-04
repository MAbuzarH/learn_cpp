// optimal approch;
#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> arr1{1, 2, 4, 5};
    vector<int> arr2{1, 2, 7, 8, 9, 11};

    vector<int> UnionArray;

    int n1 = arr1.size();
    int n2 = arr2.size();

    int i = 0;
    int j = 0;

    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            if (UnionArray.size() == 0 || UnionArray.back() != arr1[i])
            {
                UnionArray.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if (UnionArray.size() == 0 || UnionArray.back() != arr2[j])
            {
                UnionArray.push_back(arr2[j]);
            }
            j++;
        }
    }
    while (i < n1)
    {
        if (UnionArray.size() == 0 || UnionArray.back() != arr1[i])
        {
            UnionArray.push_back(arr1[i]);
        }
        i++;
    }
    while (j < n2)
    {
        if (UnionArray.size() == 0 || UnionArray.back() != arr2[j])
        {
            UnionArray.push_back(arr2[j]);
        }
        j++;
    }

    for(int k = 0; k < UnionArray.size(); k++){
        cout<<UnionArray[k]<<" ";
    }
    return 0;
}