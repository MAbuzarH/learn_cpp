#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> arr{1, 2, 3, 0, 4, 5, 0, 0, 6, 0};
    int j = -1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }
    if (j == -1)
    {
        cout << "no zeros in given array" << endl;
    }
    for (int k = j + 1; k < arr.size(); k++)
    {
        if (arr[k] != 0)
        {
            swap(arr[k], arr[j]);
            j++;
        }
    }

for(int l =0; l<arr.size(); l++){
cout<< arr[l]<<" ";
}
    return 0;
}