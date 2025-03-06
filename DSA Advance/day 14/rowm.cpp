#include <iostream>
using namespace std;
int main()
{
    //for row majior go left to right
    // for col majior go right to left
    int A[3][4] = {{1, 2, 3, 4},
                   {5, 6, 7, 8},
                   {9, 10, 11, 12}};
    int m = 3, n = 4;
    // cout << "Enter row number \n";
    // cin >> m;
    // cout << "Enter col number \n";
    // cin >> n;
    // cout << "element on yor destination is : " << A[m][n] << endl;
    int B[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    // m=3 n= 4;
    // i=2 j=1
    int i = 2, j = 1;
    int k = (i * n) + j;
    cout << "element on yor destination is : " << B[k] << endl;
    return 0;
}