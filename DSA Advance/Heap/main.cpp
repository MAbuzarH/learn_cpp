#include <iostream>

using namespace std;

void insert(int A[], int n)
{
    // this take time O(log(n))
    int temp, i = n;
    temp = A[i];
    while (i > 1 && temp > A[i / 2])
    {
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
}

// Inplace heap creation:  when one array is used

void createHeap()
{
    // time of creating a heap is (n log n)
    int A[] = {0, 10, 20, 30, 25, 5, 40, 35};
    int i;
    for (i = 2; i < 7; i++)
    {
        insert(A, i);
    }
}

int Delet(int A[], int n)
{
    int x, i, j, temp, val;
    val = A[1];
    x = A[n];
    A[1] = A[n];
    A[n] = val;
    i = 1, j = i * 2;
    while (j < n - 1)
    {
        if (A[j + 1] > A[j])
        {
            j = j + 1;
        }
        if (A[i] < A[j])
        {
            // swap(A[i], A[j]);
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * j;
        }
        else
        {
            break;
        }
    }
    // A[n] = x;
    return val;
}

int main()
{
    // int H[] = {0, 2, 5, 8, 9, 4, 10, 7};
    int H[] = {0, 10, 20, 30, 25, 5, 40, 35};
    for (int i = 2; i <= 7; i++)
    {
        insert(H, i);
    }

    // display
    cout << "Display before deletion: ";
    for (int i = 0; i <= 7; i++)
    {
        cout << H[i] << " ";
    }

    cout << "\nDeleted value is:" << Delet(H, 7) << endl;

    cout << "Display after deletion: ";
    for (int i = 0; i <= 7; i++)
    {
        cout << H[i] << " ";
    }

    return 0;
}