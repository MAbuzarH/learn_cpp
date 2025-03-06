#include <iostream>
#include <stdlib.h>
using namespace std;
struct box
{
    int length;
    int width;
};
int main()
{
    // struct box b{10, 20};
    // struct box *p;
    // p = &b;
    // (*p).length = 20;
    // cout << b.length << endl;
    // p->width = 40;
    // cout << b.width << endl;

    // creating in heap //dinamic
    struct box *p;
    p = (struct box *)malloc(sizeof(struct box));
    cout << sizeof(p) << endl;
    p->length = 20;
    p->width = 10;
    cout << p->length << endl;
    cout << p->width << endl;
    return 0;
}