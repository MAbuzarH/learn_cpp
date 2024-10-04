#include <iostream>
using namespace std;

void Reverse(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    int s = 4;
    int arr[s] = {-1, -100, 3, 99};
    int d = 2;
    d = d % s;
    int start = 0;
    Reverse(arr, start, d);
    Reverse(arr, d + 1, s - 1);
    Reverse(arr, start, s - 1);
    for (int i = 0; i < s; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}