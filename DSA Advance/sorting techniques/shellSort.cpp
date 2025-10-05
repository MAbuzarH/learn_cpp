// in insertion sort we are comparing 2 adjasent elements and sorting but here is a new concept insted of coparing to adjasent element you should compare 2 distinct element and distance between them is known as gap or intervel effeciency of sell sort depend on the gap ,if we chose gap wisly we save to much swaps there are many ways to calculate gaps
// we decrese the gap throught process until we reach 1 when gap =1 shell sort work same like insertion sort we can take gap = flor(n/2) where n is number of elements

#include <iostream>
using namespace std;

void display(int A[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << A[i] << " ";
  }
  cout << endl;
}

void swap(int *p, int *q)
{
  int temp = *p;
  *p = *q;
  *q = temp;
}

void shellSort(int A[], int n)
{

  // assigning gap n/2 every time
  for (int gap = n / 2; gap >= 1; gap = gap / 2)
  {
    // writing another for loop for j
    for (int j = gap; j < n; j++)
    {
      // if we take n = 4 so i =0 here j - gap;
      // here i-gap give '-' value most of time bc when swap done we need to check previous value also
      for (int i = j - gap; i >= 0; i - gap)

      {
        if (A[i + gap] > A[i])
        {
          break;
        }
        else
        {
          swap(&A[i + gap], &A[i]);
        }
      }
    }
  }
}

int main()
{
  int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11};
  int n = 9;

  display(A, n);
  // CountSort(A, n);
  shellSort(A, n);
  display(A, n);
  return 0;
}