#include <iostream>
using namespace std;
// // call by address
// void swap(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }
// int main()
// {
//     int a = 10;
//     int b = 30;
//     swap(&a, &b);
//     printf("a = %d, b = %d", a, b);
//     return 0;
// }
// call by refrence
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int main()
{
    int a = 10;
    int b = 30;
    swap(a, b);
    printf("a = %d, b = %d", a, b);
    return 0;
}