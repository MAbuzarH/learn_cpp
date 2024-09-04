#include <iostream>
using namespace std;

int main() {
  int a[2][3] = { {3, 5, 6}, {1, 2, 4} };
  int sum = 0;
  int *p = *a;
  
  for (int i = 0; i < 6; i += 2, p += 2) {
    sum += *p;
  }
  
  cout << sum;

  return 0;
}
