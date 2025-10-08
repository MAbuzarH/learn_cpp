#include <iostream>
using namespace std;

void function1(int a);
void function2(int b);
void function3(int c);
int main()
{
  void (*fun[3])(int) = {function1, function2, function3};
  printf("%s", "Enter a number between 0 and 2, 3 to end: ");
  int choice = 0;
  cin >> choice;
  while (choice >= 0 && choice < 3)
  {
    (*fun[choice])(choice);
    printf("%s", "Enter a number between 0 and 2, 3 to end: ");
    scanf("%d", &choice);
  }

  return 0;
}
void function1(int a)
{
  printf("You entered %d so function1 was called\n\n", a);
}

void function2(int b)
{
  printf("You entered %d so function1 was called\n\n", b);
}
void function3(int c)
{
  printf("You entered %d so function1 was called\n\n", c);
}