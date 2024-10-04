#include <bits/stdc++.h>
// batter approch
using namespace std;

// int main()
// {
//     int n = 5;
//     // int arr[n] = {29, 1, 34, 22, 76};
//     int arr[n] = {12, 35, 1, 10, 34, 1};
//     int large = arr[0];
//     bool result = false;
//     int secondLarge = INT_MIN;

//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] > large)
//         {
//             large = arr[i];
//         }
//     }

//     for (int j = 0; j < n; j++)
//     {
//         if (arr[j] < large && arr[j] > secondLarge)
//         {
//             secondLarge = arr[j];
//             result = false;
//         }
//         else
//         {
//             result = true;
//         }
//     }

//     if (result)
//     {
//         cout << "Not found \n";
//     }
//     else
//     {
//         cout << "second Large:" << secondLarge << endl;
//     }

//     return 0;
// }

int getSecondLargest(vector<int> &arr)
{
    // Code Here
    int large = INT_MIN;
    int n = arr.size();
    int secondLarge = INT_MIN;
    // bool result = false;

    // check
    if (n < 2)
    {
        return -1; // Not enough elements for comparison
    }

    // find large
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > large)
        {
            large = arr[i];
        }
    }
    // find 2nd large
    for (int j = 0; j < n; j++)
    {
        if (arr[j] < large && arr[j] > secondLarge)
        {
            secondLarge = arr[j];
        }
    }
    if (secondLarge == INT_MIN)
    {
        return -1;
    }
    else
    {
        // cout << "second Large:" << secondLarge << endl;
        return secondLarge;
    }
}
int main()
{
    vector<int> arr{12, 35, 1, 10, 34, 1};
    int result = getSecondLargest(arr);

    cout << result;

    return 0;
}