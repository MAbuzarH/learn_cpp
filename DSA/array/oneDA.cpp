#include <bits/stdc++.h>
using namespace std;

int main()
{
    int size;

    cout << "Enter the size of the array" << endl;
    cin >> size;

    int *arr = new int[size];

    cout << "Enter the data" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "the data is : ";
    for (int j = 0; j < size; j++)
    {
        cout << arr[j] << " ";
    }

    delete[] arr;
    return 0;
}