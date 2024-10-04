#include <iostream>
using namespace std;

void buble_Sort(int arr[], int size)
{
    for (int i = size - 1; i >= 1; i--)
    {
        int didswap = 0;
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                didswap = 1;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (didswap == 0)
        {
            break;
        }
        cout << "runs \n";
    }
}

int main()
{
    int s = 6;
    int arr[s] = {1, 2, 4, 7, 10, 3};
    buble_Sort(arr, s);
    for (int k = 0; k < s; k++)
    {
        cout << arr[k] << " ";
    }
    return 0;
}