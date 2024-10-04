#include <bits/stdc++.h>
using namespace std;

void recursiveBubbleSort(int arr[], int n)
{
    // base case
    if (n == 1)
        return;
    // swap if needed
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i+1]);
        }
    }
    // recursive case
    recursiveBubbleSort(arr, n - 1);
}

int main()
{
    int size = 6;
    int arr[size] = {4, 2, 3, 10, 5};
    recursiveBubbleSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}