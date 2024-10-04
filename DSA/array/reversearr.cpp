#include <bits/stdc++.h>
using namespace std;
int main()
{
    int size = 10;
    int arr[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int start = 0;
    int end = size - 1;
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        cout << " " << arr[i] << " ";
    }
    cout << "]";
    return 0;
}