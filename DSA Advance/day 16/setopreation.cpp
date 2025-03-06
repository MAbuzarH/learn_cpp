#include <iostream>
using namespace std;

void uni(int A[], int m, int B[], int n)
{
    int i = 0, j = 0, k = 0;
    int C[10];
    while (i < m && j < n)
    {
        if (A[i] < B[j])
        {
            C[k++] = A[i++];
        }
        else if (B[j] < A[i])
        {
            C[k++] = B[j++];
        }
        else
        {
            C[k++] = A[i++];
            j++;
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
    for (int o = 0; o < k; o++)
    {
        cout << C[o] << " ";
    }
}

void Intersec(int A[], int m, int B[], int n)
{
    int i = 0, j = 0, k = 0;
    int C[10];
    while (i < m && j < n)
    {
        if (A[i] < B[j])
        {
            i++;
        }
        else if (B[j] < A[i])
        {
            j++;
        }
        else
        {
            C[k++] = A[i++];
            j++;
        }
    }
    for (int o = 0; o < k; o++)
    {
        cout << C[o] << " ";
    }
}

// difrence A-B
void Difrence(int A[], int m, int B[], int n)
{
    int i = 0, j = 0, k = 0;
    int C[10];
    while (i < m && j < n)
    {
        if (A[i] < B[j])
        {
            C[k++] = A[i++];
        }
        else if (B[j] < A[i])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    for (; i < m; i++)
    {
        C[k++] = A[i];
    }
    for (int o = 0; o < k; o++)
    {
        cout << C[o] << " ";
    }
}

int main()
{
    int m = 5, n = 5, l = m + n;

    int A[m] = {3, 4, 6, 7, 8};
    int B[n] = {1, 6, 8, 10, 12};

    // uni(A, m, B, n);
    // Intersec(A, m, B, n);
    Difrence(A, m, B, n);
    // union of sets
}