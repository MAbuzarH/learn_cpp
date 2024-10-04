#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int size)
{
    for (int i = 0; i <= size - 1; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            // swap(arr[j - 1], arr[j]);
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
            cout << "run \n";
        }
    }
}

int main()
{
    int s = 6;
    int arr[s] = {3, 2, 4, 7, 10, 1};
    insertion_sort(arr, s);
    for (int k = 0; k < s; k++)
    {
        cout << arr[k] << " ";
    }
    return 0;
}