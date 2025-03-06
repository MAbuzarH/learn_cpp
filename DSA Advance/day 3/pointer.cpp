#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct box
{
    int length;
    int width;
};
int main()
{
    // pointer
    // int a = 10;
    // int *p;
    // p = &a;
    // cout << "p=" << p << endl; //print addres of a
    // cout << "&a=" << &a << endl;//print addres of a
    // cout << "*P=" << *p << endl;//print value of a
    // pointer to an array
    // int A[5] = {1, 2, 3, 4, 5};
    // int *p;
    // p = A;
    // for (int i = 0; i < 5; i++)
    // {
    //     // printf("%d ",*p[i]);
    //     cout << p[i] << endl;
    // }

    // int *p = new int[5];
    // int *p;
    // p=(int*)malloc(5*sizeof(int));
    // for (int i = 0; i < 5; i++)
    // {
    //     p[i] = i;
    // }
    // for (int j = 0; j < 5; j++)
    // {
    //     cout << p[j] << endl;
    // }
    // // delete[] p;
    // free(p);
    // all type of pointers takes same size of memory
    // which is 4 bytes
    int *p1;
    float *p2;
    char *p3;
    double *p4;
    struct box *p5;
    cout << sizeof(p1) << endl;
    cout << sizeof(p2) << endl;
    cout << sizeof(p3) << endl;
    cout << sizeof(p4) << endl;
    cout << sizeof(p5) << endl;
    return 0;
}