// Insertion sort:
//  it means we have a sorted array and we want to sort element on its correct position
// from the last start comparing each element with your new element and if element is grater shift it if element smaller then key (new element to insert) insert key to i+1
// if we impliment this using ll so we need 2 pointer one is temp to compare and other is tail which follow temp;
// time taken min: O(1) max: O(n)
// Analysis:
// NUmber of passes:n-1
// number of comparision: 1+2+...+n-1;
// insertion sort is more useful while impliment with linked list it is design for ll
// time taken if list is sorted O(n)
// number of swap O(1)
// insertion sort is adaptive (its nature by self is adoptive we dont use any flag or etc)
// insertion sort is adaptive and stable

#include <iostream>
using namespace std;

void InsersionSort(int A[], int n)
{
    int x, j;
    for (int i = 1; i < n; i++)
    {
        j = i - 1;
        x = A[i];
        while (j >= 0 && A[j] > x)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
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
    InsersionSort(A, 10);
    display(A, n);
    return 0;
}
