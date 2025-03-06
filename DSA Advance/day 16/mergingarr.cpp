#include <iostream>
using namespace std;
void Display(int arr[], int s)
{
    for (int i = 0; i < s; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int m = 5, n = 5;
    int A[m] = {1, 3, 5, 8, 10};
    int B[n] = {2, 4, 6, 7, 9};
    int i = 0, j = 0, k = 0;
    int l = m + n;
    int C[l];
    while (i < m && j < n)
    {
        if (A[i] < B[j])
        {
            C[k++] = A[i++];
        }
        else
        {
            C[k++] = B[j++];
        }
    }
    for (; i < m; i++)
    {
        C[k++] = A[i];
    }
    for (; j < n; j++)
    {
        C[k++] = B[j];
    }
    Display(C, l);
}