#include <iostream>
#include <stdio.h>
using namespace std;

struct triangle
{
    int length;
    int bredth;
    char x;
};
int main()
{
    struct triangle t1 = {10, 20};
    cout << sizeof(t1) << " "; // now size is 12b because of memory pading
    cout << t1.length << " " << t1.bredth << endl;
}