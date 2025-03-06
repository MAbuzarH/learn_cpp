#include <iostream>
using namespace std;
int main()
{
    int *p;
    int *q;
    p = new int[5];
    q = new int[10];
    for (int i = 0; i < 5; i++)
    {
        p[i] = i + 2;
        q[i] = p[i];
    }
    delete[] p;
    p = q;
    q = NULL;
    p[5] = 20;
    p[6] = 80;
    for (int j = 0; j < 10; j++)
    {
        printf("%d ", p[j]);
    }

    delete[] q;
    return 0;
}