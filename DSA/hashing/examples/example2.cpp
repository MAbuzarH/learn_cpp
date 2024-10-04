#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "enter length number of arr";
    cin >> n;
    int arr[n];
    cout << "Enter the elements \n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    map<int, int> mapp;
    for (int i = 0; i < n; i++)
    {
        mapp[arr[i]]++;
    }

    int q;
    cout << "Enter the number of query:";
    cin >> q;

    while (q--)
    {
        int num;

        cout << "Enter the number to find:";
        cin >> num;
        cout << num << " : " << mapp[num] << endl;
    }
    return 0;
}