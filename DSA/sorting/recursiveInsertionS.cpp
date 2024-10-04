#include <bits/stdc++.h>
using namespace std;
void insertionSort(int arr[], int n)
{
    if (n == 1)
        return;

    // recursive case
    insertionSort(arr, n - 1);

    // Insert the nth element into the sorted part
    int last = arr[n - 1];
    int j = n - 2;

    // Shift elements to the right to make room for the last element
    while (j >= 0 && arr[j] > last)
    {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = last;
}
int main()
{
    int s = 5;
    int arr[s] = {4, 3, 1, 7, 2};
    insertionSort(arr, s);

    for (int i = 0; i < s; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}