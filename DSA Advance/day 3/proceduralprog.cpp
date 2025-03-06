#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct Rectangle
{
    int length;
    int breadth;
};

int area(struct Rectangle r)
{
    return r.length * r.breadth;
}
int paremeter(struct Rectangle r)
{
    int p = 2 * (r.length + r.breadth);
}
void initilize(struct Rectangle *p, int l, int b)
{
    p->length = l;
    p->breadth = b;
}
int main()
{
    struct Rectangle r1;
    int l, b;
    cout << "enter Length" << endl;
    cin >> l;
    cout << "enter breadth" << endl;
    cin >> b;
    initilize(&r1, l, b);
    int a = area(r1);
    int p = paremeter(r1);
    printf("area = %d\nparemeter = %d \n", a, p);
}