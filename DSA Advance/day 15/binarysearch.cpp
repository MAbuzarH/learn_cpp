#include <iostream>
using namespace std;

int bainary_search(int arr[], int size, int l, int h, int k)
{
    while (l <= h)
    {
        int m = (l + h) / 2;
        if (k == arr[m])
        {
            return m;
        }
        else if (k < arr[m])
        {
            h = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    return -1;
}
int main()
{
    int size = 10;
    int arr[size] = {1, 3, 5, 6, 8, 9, 13, 15, 33, 44};
    int l = 0, h = size, key = 15;
    cout << bainary_search(arr, size, l, h, 3);
}