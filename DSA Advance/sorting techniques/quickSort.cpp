// Quick sort:
// the main idea is the a number n is placed in that place where all elements greterthan n are on rite side of n and all the elements less from n  come on left side
// it use partitioning procedgure to sort this and it is recursive
// time complexity O(n^2)
// quick sort is based on povit and partation
// pick the povit and preform partation on the bases of that povit point
// then call QuickSort() for left half and right half
// in avarage cases time compleity (n log n) && worst case
//(O(n^2))
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

int partition(int A[], int start, int end)
{
  int pivot = A[end];
  int index = start - 1;
  int j;
  // j is used to itreate whole array
  // index make place for povit position
  for (j = start; j < end; j++)
  // first here i made mistake
  // my code j = 0
  // correct code j= start bc we call it recursively some time start value may not be 0 so logicaly it fails
  {
    if (A[j] <= pivot)
    {
      index++;
      swap(&A[j], &A[index]);
    }
  }
  index++;
  swap(&A[index], &A[end]);
  return index;
}

void QuickSort(int *A, int start, int end)
{
  int pivIdx;
  if (start < end)
  {
    pivIdx = partition(A, start, end);
    QuickSort(A, start, pivIdx - 1);
    QuickSort(A, pivIdx + 1, end);
  }
}
int main()
{
  int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
  int n = 10;

  display(A, n);

  QuickSort(A, 0, n - 1);
  

  display(A, n);
  return 0;
}