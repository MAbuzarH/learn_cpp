#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct Array
{
    int p[10];
    int size;
    int length;
};
void Display(struct Array arr)
{
    printf("Array Element are: \n");
    for (int i = 0; i < arr.length; i++)
        cout << arr.p[i] << " ";
}

void Insert(struct Array *arr, int index, int x)
{
    int i;
    if (index >= 0 && index < arr->length)
    {
        for (i = arr->length; i < index; i--)
        {
            arr->p[i] = arr->p[i - 1];
        }
        arr->p[index] = x;
        arr->length++;
    }
}
void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->p[arr->length++] = x;
    }
}

void Delete(struct Array *arr, int index)
{
    int x = arr->p[index];
    int i;
    if (index >= 0 && index <= arr->length)
    {
        for (i = index; i < arr->length; i++)
        {
            arr->p[i] = arr->p[i + 1];
        }
        --(arr->length);
    }
}

int linear_search(struct Array *arr, int key)
{
    for (int i = 0; i < arr->length; i++)
    {
        if (arr->p[i] == key)
        {
            swap(arr->p[i], arr->p[i - 1]);
            return i;
        }
    }
    return -1;
}
int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    // arr.p= new int(arr.size);
    Append(&arr, 20);
    cout << arr.length << endl;
    Insert(&arr, 2, 40);
    // Delete(&arr, 2);
    // cout << arr.length << endl;
    cout << linear_search(&arr, 40) << endl;

    Display(arr);
    return 0;
}