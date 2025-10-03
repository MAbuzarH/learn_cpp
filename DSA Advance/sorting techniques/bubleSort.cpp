// Buble sort:
//  sorting element by comparing and swaping 2 adjesant element and larger element go to end in one pass we sort one element and doing again again we sort all the array
// Analysis:
// we have total element n = 5
// 4 passes done to sort this so (n-1)passes
// no of comparision: 1+2+3+4 || 1+2+3+4+...+n-1
// so this is n(n-1)/2 O(n^2)
// Max number of swap:1 +2 +3 +4 || 1+2+3+4+...+n-1
// so this is also n(n-1)/2 O(n^2)
// minimum time taken O(n)
// it also satisfiy adoptive property by using flag variable
// buble sort is stable also

#include <iostream>
using namespace std;

void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}
void BubleSort(int A[], int n)
{
    int flag;
    // this loop is for number of pases
    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(&A[j], &A[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
            return;
    }
}

void display(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}
int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int n = 10;

    display(A, n);

    BubleSort(A, n);

    display(A, n);

    return 0;
}