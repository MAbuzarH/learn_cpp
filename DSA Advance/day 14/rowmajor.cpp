#include <iostream>
using namespace std;
int main()
{
    // int A[3][4] ={{1,2,3,4},
    //               {5,6,7,8},
    //               {9,10,11,12}};
    // so this array using row majior
    int A[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int i = ((1 * 4) + 2);
    cout << A[i];
    // m = 3 , n= 4
    // Addr(A[2][3]) = L +[2*4 + 3]* w
    // in general(A[i][j]) = L + [i*n + j]* w
    // eg L = 200 starting index and w = 2;
    // =200 +11*2
    //= 222 is the address of A[2][3]
}