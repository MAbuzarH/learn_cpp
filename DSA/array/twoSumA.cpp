#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> arr{1, 2, 9, 5, 3, 5};
    int target = 7;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {

            if (arr[i] + arr[j] == target)
            {
                cout << "particular index: ";
                cout << i << " : " << j << endl;
                cout << arr[i] << "+" << arr[j] << endl;
                break;
            }
        }
    }
}