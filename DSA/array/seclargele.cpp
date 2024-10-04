#include <bits/stdc++.h>
//brut fore approch;
using namespace std;
int main()
{

    int n = 5;
    int arr[n] = {76, 1, 34, 22, 76};
    // int arr[n] = {7, 7, 7, 7, 7};
    // int first = arr[0];
    // int last = arr[n - 1];
    sort(arr, arr + n);
    int secondLarge = 0;
    int largest = arr[n - 1];
    bool result = false;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] != largest)
        {
            secondLarge = arr[i];
            result = false;
            break;
        }
        else
        {
            result = true;
        }
        // cout << arr[i] << " ";
    }
    if (result)
    {
        cout << "not found" << endl;
    }
    for (int j = 0; j < n; j++)
    {
        cout << arr[j] << " ";
    }
    cout << " \n " << secondLarge << " ";
    return 0;
}