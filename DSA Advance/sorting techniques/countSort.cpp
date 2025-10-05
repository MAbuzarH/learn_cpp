// count Sort
// it is index based sorting and it is fastest but it consume lot of memory
// we take an extra array which size is equal to maximum number prasent in the array we want to sort we make every element of new array to 0 and loop through original array and on each number we will increment index of tep arrays value eg if we got 3 in our array we mark 3rd index of temp array as 1 and so on after completing this step for complete array we take temp arry and a new array "ntemp" and we use temp arrays index as value if it is greter than 0 (value 0)
// it takes O(n) time

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

int findMax(int A[], int n)
{
  int max = A[0];
  for (int i = 1; i < n; i++)
  {
    if (A[i] > max)
    {
      max = A[i];
    }
  }
  return max;
}

void CountSort(int A[], int n)
{
  int max = findMax(A, n);
  int *count;
  count = new int[max + 1];

  for (int i = 0; i < max + 1; i++)
  {
    count[i] = 0;
  }
  for (int j = 0; j < n; j++)
  {
    count[A[j]]++;
  }
  int k = 0, l = 0;
  while (k < max + 1)
  {
    if (count[k] > 0)
    {
      A[l++] = k;
      count[k]--;
    }
    else
    {
      k++;
    }
  }
}

int main()
{
  int A[] = {3, 6, 9, 3, 8, 6, 12, 4, 15, 2, 6, 14};
  int n = 12;

  display(A, n);
  CountSort(A, n);
  display(A, n);
  return 0;
}