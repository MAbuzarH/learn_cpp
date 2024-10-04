#include <iostream>
using namespace std;
int main()
{
    // brote force approch;
    int s = 15;
    int arr[s] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    int d = 9;
    d = d % s;
    int temp[d];
    for (int i = 0; i < d; i++)
    {
        temp[i] = arr[i];
    }

    for (int j = d; j < s; j++)
    {
        arr[j - d] = arr[j];
    }

    for (int k = s - d; k <= s; k++)
    {
        arr[k] = temp[k - (s - d)];
    }
    for (int l = 0; l < s; l++)
    {
        cout << arr[l] << " ";
    }
    return 0;
}