#include <iostream>
using namespace std;
int count = 0;

int binarySearch(int array[], int x, int low, int high)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;

        // If found at mid, then return it
        if (x == array[mid])
        {
            count++;
            return mid;
        }

        // Search the right half
        if (x > array[mid])
        {
            count++;
            return binarySearch(array, x, mid + 1, high);
        }

        // Search the right half
        count++;
        return binarySearch(array, x, low, mid - 1);
    }

    return -1;
}
int main()
{

    int n = 50;
    int arr[n];
    for (int i = 1; i <= n; i++)
    {
        arr[i] = i;
    }

    int toFind = 1;

    int low = arr[0];
    int high = arr[n - 1];
    // int mid = low +(high - low)/2;

    cout << binarySearch(arr, toFind, low, high);
    cout << count;
    return 0;
}