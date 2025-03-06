#include <iostream>
using namespace std;
int main()
{
    int m = 3, n = 4;
    int B[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    // m=3 n= 4;
    // i=2 j=1
    int i = 2, j = 1;
    int k = (j * m) + i;
    cout << "element on yor destination is : " << B[k] << endl;

    return 0;
}