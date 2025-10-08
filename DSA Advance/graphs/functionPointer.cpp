#include <iostream>
using namespace std;
#define SIZE 10
void Bubble(int work[], size_t size, int (*compare)(int a, int b));
int ascending(int a, int b);
int descending(int a, int b);
int main()
{
  int order;
  int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};
  cout << "Enter 1 to Use Assanding 2 to use Desen";
  cin >> order;

  cout << "orignal array:";
  for (int i = 0; i < SIZE; i++)
  {
    cout << a[i] << " ";
  }
  if (order == 1)
  {
    cout << "useed ascending \n";
    Bubble(a, SIZE, ascending);
  }
  else
  {
    cout << "useed descending \n";
    Bubble(a, SIZE, descending);
  }

  for (int i = 0; i < SIZE; i++)
  {
    cout << a[i] << " ";
  }
  return 0;
}

void swap(int *element1Ptr, int *element2Ptr)
{
  int hold = *element1Ptr;
  *element1Ptr = *element2Ptr;
  *element2Ptr = hold;
}

void Bubble(int work[], size_t size, int (*compare)(int a, int b))
{
  void swap(int *element1Ptr, int *element2ptr);
  for (int pass = 1; pass < size; pass++)
  {
    for (int count = 0; count < size - 1; count++)
    {
      if ((*compare)(work[count], work[count + 1]))
      {
        swap(&work[count], &work[count + 1]);
      }
    }
  }
}

int ascending(int a, int b)
{
  return a < b;
}
int descending(int a, int b)
{
  return a > b;
}