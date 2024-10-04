//selection sort 
#include <bits/stdc++.h>
using namespace std;
void selection_Sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        // swap(arr[i], arr[min]);
        // swap the array to
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
        // cout << arr[i] << " ";
    }
}
int main()
{
    int size = 5;
    int arr[size] = {4, 1, 3, 9, 7};
    selection_Sort(arr, size);
    for (int k = 0; k < size; k++)
    {
        cout << arr[k] << " ";
    }
    // for (int i = 0; i < 6; i++)
    // {
    //     int min = i;
    //     for (int j = i; j < 6; j++)
    //     {
    //         if (arr[j] < arr[min])
    //         {
    //             min = j;
    //         }
    //     }
    //     // swap(arr[i], arr[min]);
    //     // swap the array to
    //     int temp = arr[min];
    //     arr[min] = arr[i];
    //     arr[i] = temp;
    //     // cout << arr[i] << " ";
    // }

    return 0;
}