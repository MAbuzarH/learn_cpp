#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct Array
{
    int *p;
    int size;
    int length;
};
void Display(struct Array arr)
{
    printf("Array Element are: \n");
    for (int i = 0; i < arr.length; i++)
        cout << arr.p[i] << endl;
}
int main()
{
    struct Array arr;
    printf("Enter the size of array:");
    scanf("%d", &arr.size);
    // arr.p= new int(arr.size);
    arr.p = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;
    int n, i;
    cout << "Enter number of Numbers:";
    scanf("%d", &n);
    printf("Enter Elements of array: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr.p[i]);
    arr.length = n;
    Display(arr);
    return 0;
}