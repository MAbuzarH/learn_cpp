#include <iostream>
using namespace std;

int sum(int a, int b)
{
  return a + b;
}

int subtract(int a, int b)
{
  return a - b;
}

int multiply(int a, int b)
{
  return a * b;
}

int divide(int a, int b)
{
  return a / b;
}

void calculater(int a, int b, int (*calculation)(int a, int b))
{
  int answer;
  answer = (*calculation)(a, b);
  // calling function could be done in this way also calculation(a, b)
  // answer = calculation(a, b);
  //but the best way is line 27 way of calling 
  cout << "Answer is:" << answer << endl;
}

int main()
{
  int order, a, b;
  cout << "enter 1st value:";
  cin >> a;
  cout << "enter 2nd value:";
  cin >> b;

  cout << "Enter 1 for sum,Enter 2 for Sub,Enter 3 for mul,Enter 4 for div:";
  cin >> order;

  switch (order)
  {
  case 1:
    calculater(a, b, sum);
    break;
  case 2:
    calculater(a, b, subtract);
    break;
  case 3:
    calculater(a, b, multiply);
    break;
  case 4:
    calculater(a, b, divide);
    break;
  default:
    cout << "Wrong input\n";
    break;
  }

  return 0;
}