// Merg sort
// total time taken nlogn time
// n time marging take place
// if we represent merging in form of tree it is full binary tree and we use post order of tree merging is done
// if it is recursive it use stack and size of stack is n log n it need extra array total space (2n+log n) n+logn is extra space used aray
// if we have an array have 8 element we think this as 8 lists having 1 element each we prform only marging on 2 list now we got 4 list have 2 elements then we merge 2 2 and then we got 2 sorted list of 4 elements in our 2nd pass then in 3rd pass we got our entire array would sorted in just 3 passes and time complexity is O(n log n) we use recursive and itrative verision of this

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

void Merge(int A[], int l, int mid, int h)
{
  int i, j, k;
  i = l;
  j = mid + 1;
  k = l;

  int C[100];
  while (i <= mid && j <= h)
  {
    if (A[i] < A[j])
    {
      C[k++] = A[i++];
    }
    else
    {
      C[k++] = A[j++];
    }
  }
  for (; i <= mid; i++)
  {
    C[k++] = A[i];
  }

  for (; j <= h; j++)
  {
    C[k++] = A[j];
  }

  // copied marged element back to a
  for (int p = l; p <= h; p++)
  {
    A[p] = C[p];
  }
}

void IMergeSort(int A[], int n)
{
  int p, l, mid, h, i;
  for (p = 2; p <= n; p = p * 2)
  {
    for (i = 0; i + p - 1 < n; i = i + p)
    {
      l = i;
      h = i + p - 1;
      mid = (l + h) / 2;
      Merge(A, l, mid, h);
    }
  }
  if (p / 2 - 1 < n)
    Merge(A, 0, p / 2 - 1, n - 1);
}

void MergeSort(int A[], int l, int h)
{
  int mid;
  if (l < h)
  {
    mid = (l + h) / 2;
    MergeSort(A, l, mid);
    MergeSort(A, mid + 1, h);
    Merge(A, l, mid, h);
  }
}
int main()
{
  int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2, 1};

  int n = 11;
  // int m = 4;
  display(A, n);

  // IMergeSort(A, n);
  MergeSort(A, 0, n - 1);
  display(A, n);
  return 0;
}

// this is for 2 sapret arrays
//  void Marge(int A[], int B[], int m, int n)
//  {
//    int i, j, k;
//    i = j = k = 0;
//    int o = m + n;
//    int C[o] = {0};
//    while (i < m && j < n)
//    {
//      if (A[i] < B[j])
//      {
//        C[k++] = A[i++];
//      }
//      else
//      {
//        C[k++] = B[j++];
//      }
//    }
//    for (; i < m; i++)
//    {
//      C[k++] = A[i];
//    }

//   for (; j < n; j++)
//   {
//     C[k++] = B[j];
//   }

//   cout << "Merged array: ";
//   display(C, o);
// }