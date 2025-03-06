#include <iostream>
using namespace std;
// struct box
// {
//     int length;
//     int width;
//     int arr[3];
// };

// //call by value
// void fun(struct box b)
// {
//     b.length = 60;
//     cout << b.length << " " << b.width << " " << endl;
// }
// int main()
// {
//     struct box b{10, 15};
//     fun(b);
//     printf("length: %d\n width: %d\n", b.length, b.width);
//     return 0;
// }

// call by address
// void fun(struct box *p)
// {
//     p->length = 60;
//     p->arr[0] = 40;
//     cout << p->length << " " << p->width << " " << endl;
// }
// int main()
// {
//     struct box b{10, 15, {1, 2, 3}};
//     fun(&b);
//     printf("length: %d\n width: %d\n arr[0] %d \n", b.length, b.width, b.arr[0]);
//     return 0;
// }

// returning a struct pointer
struct box
{
    int length;
    int width;
};

struct box *fun()
{
    struct box *p;
    p = new struct box;
    // p=(struct box *)malloc(sizeof(struct box));
    p->length = 20;
    p->width = 10;
    return p;
}
int main()
{
    struct box *p;
    p = fun();
    cout << p->length << " " << p->width << " \n";
}