#include <bits/stdc++.h>

using namespace std;

int partitio(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pIndex = partitio(arr, low, high);
        quickSort(arr, low, pIndex - 1);
        quickSort(arr, pIndex + 1, high);
    }
}

int main()
{
    // int size = 7;

    vector<int> arr{24, 18, 38, 43, 14, 40, 1, 54};
    int low = 0;
    int high = arr.size() - 1;
    quickSort(arr, low, high);

    for (int i = 0; i < high; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}