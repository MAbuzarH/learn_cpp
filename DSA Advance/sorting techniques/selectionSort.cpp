// selection sort
// we select an index and find minimum number and put that number on that location
// Analysis:
// number of compaision: 1+2+...+n-1 so n(n-1)/2 O(n^2)
// number of swap: n-1 so O(n)
// if i prform just 1 swap i got smallest element
// in buble sort we got k larger element but in this we got K smaller
// it is not adaptive
// it is not stable
#include <iostream>
using namespace std;

void swap(int *p, int *q)
{
  int temp = *p;
  *p = *q;
  *q = temp;
}
void display(int A[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << A[i] << " ";
  }
  cout << endl;
}

void searchSort(int A[], int n)
{
  int k, j;
  for (int i = 0; i < n - 1; i++)
  {
    for (j = k = i; j < n; j++)
    {
      if (A[j] < A[k])
      {
        k = j;
      }
    }
    swap(&A[i], &A[k]);
  }
}
int main()
{
  int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
  int n = 10;

  display(A, n);

  searchSort(A, n);

  display(A, n);

  return 0;
}