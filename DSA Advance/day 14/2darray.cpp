#include <iostream>
using namespace std;
int main()
{
    // methode of creating 2d array
    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
    // using pointer created in heap
    int *B[3];
    B[0] = new int[2];
    B[1] = new int[2];
    B[2] = new int[2];
    B[0][1] = {2};
    cout << B[0][1];

    // cout << B + 4;
    // using double pointer;
    int **C;
    C = new int *[2];
    C[0] = new int[1];
    C[1] = new int[1];
    cout << C;
}
//why array indexing in some languages start from 0;
// the formula of accessing an element of array starting 
// from 0th index is Address(A[i]) = L + (i * (size of datatype))
// for int = L + (i * (4)); // by using this we can find address
// but if we start from 1 so formula will change
// = L +(i -1)*(size of datatype)
// = L +(i -1)*w; 
// where L is starting location of array i is index 