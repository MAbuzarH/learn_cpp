// linear probing
// it come under close hashing
//  we have fixed space so store valuse so we use new hash function buy using that if we face any colision we fill the value in next free space avaliable in hashtable
//  function we use is h'(x) =(h(x) + f(i))%10; where f(i)=i ,i =0,1,2,3..
// lenar probing is littel bit timetaking
// lamda is always <= 0.5
// while searching we use same function h(x) = x / 10; when we found empty space while serching it means no element is there
// avrage successfull searh t = (1/lamda)ln(1/1-lambda)
// avrage un successfull searh t = 1/(1 - lambda)
// linear probing have a draw back : clustring of values at one place
// deleting:
// first finde index compare prasent value to value to delete if it is not equal to vale check next untal you found it and  delete it after that take out all the keys and re enter all the value this is calledre hashing
// so this is lot of work so in linear probing we not suggest deletion
// if you realy want to delete so put flag with each remaning value
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
  while (p[(index + i) % SIZE] == key)
  {
    i++;
  }
  return (index + 1) % SIZE;
}

int prob(int H[], int key)
{
  int index = Hash(key);
  int i = 0;
  while (H[(index + i) % SIZE] != 0)
  {
    i++;
  }
  return (index + i) % SIZE;
}
// Insert into hash table using chaining
void Insert(int H[], int key)
{
  int index = Hash(key);
  if (H[index] != 0)
    index = prob(H, key);
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