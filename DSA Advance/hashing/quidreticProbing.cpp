// Quidretic Probing
// here we use function h'(x) = (h(x)+f(i))%10 where f(i) = i^2, i = 0,1,2
// insted of entring value in next avaliable index on colision we find next index by puting i^2
// avrage sucessfull search t =log(e)(1-lamda)

#include <iostream>

using namespace std;
#define SIZE 10

// Hash function
int Hash(int key)
{
  return key % 10;
} // Insert value in sorted order into linked list

// Search for key in linked list
int Search(int *p, int key)
{
  int i = 0;
  int index = Hash(key);
  while (p[(index + i * i) % SIZE] == key)
  {
    i++;
  }
  if (p[(index + i * i) % SIZE] == 0)
  {
    return -1;
  }

  return (index + i * i) % SIZE;
}

int Quidraticprob(int H[], int key)
{
  int index = Hash(key);
  int i = 0;
  while (H[(index + i * i) % SIZE] != 0)
  {
    i++;
  }
  return (index + i * i) % SIZE;
}
// Insert into hash table using chaining
void Insert(int H[], int key)
{
  int index = Hash(key);
  if (H[index] != 0)
    index = Quidraticprob(H, key);
  H[index] = key;
}

// Display hash table
void Display(int H[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << "Bin[" << i << "]: ";
    cout << H[i] << "\n";
  }
  cout << "END\n";
}

int main()
{
  int HT[10];
  for (int i = 0; i < 10; i++)
    HT[i] = 0;

  Insert(HT, 2);
  Insert(HT, 22);
  Insert(HT, 10);
  Insert(HT, 45);
  Insert(HT, 35);
  // Insert(HT, 25);

  cout << "Hash Table (with Chaining):\n";
  Display(HT, 10);

  int s = Search(HT, 22);
  if (s)
    cout << "\nFound: " << s << endl;
  else
    cout << "\nNot Found!" << endl;

  return 0;
}