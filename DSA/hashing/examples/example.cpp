#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout << "Enter the length:";
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int hash[13] = {0};
    int q;
    cout << "enter how many query u want" << endl;
    cin >> q;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0 && arr[i] < 13) // ensuring arr[i] is within the valid range
            hash[arr[i]] += 1;
    }

    // Queries
    while (q--)
    {
        int num;
        cout << "Enter the number to query: ";
        cin >> num;

        if (num >= 0 && num < 13) // ensuring query is within the valid range
            cout << "Count of " << num << ": " << hash[num] << endl;
        else
            cout << "Invalid query, number out of range!" << endl;
    }
    return 0;
}