#include <iostream>
using namespace std;
struct Array
{
    int A[10];
    int size;
    int length;
};

int get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
    {
        return arr.A[index];
    }
    return -1;
}

void set(struct Array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
    {
        arr->A[index] = x;
    }
}

int max(struct Array arr)
{
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}
int min(struct Array arr)
{
    int min = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}
int sum_all(struct Array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; i++)
    {
        sum += arr.A[i];
    }
    return sum;
}
float avg(struct Array arr)
{
    return (float)sum_all(arr) / arr.length;
}

void reverse(struct Array *arr)
{
    struct Array B = {{}, arr->size, arr->length};
    int j = 0;
    for (int i = arr->length - 1; i >= 0; i--)
    {
        B.A[j] = arr->A[i];
        j++;
    }
    for (int k = 0; k < B.length; k++)
    {
        arr->A[k] = B.A[k];
        cout << arr->A[k] << " ";
    }
}
void rev(struct Array *arr)
{

    int i, j;
    for (i = 0, j = arr->length - 1; i < arr->length, i < j; i++, j--)
    {
        int temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
    // for (int k = 0; k < arr->length; k++)
    // {

    //     cout << arr->A[k] << " ";
    // }
}

void left_shift(struct Array arr)
{
    // int temp = arr.A[0];
    for (int i = 0; i < arr.length; i++)
    {
        arr.A[i] = arr.A[i + 1];
    }
    for (int j = 0; j < arr.length; j++)
    {
        cout << arr.A[j] << " ";
    }
}

void insert_sorted(struct Array *arr, int x)
{
    int i = arr->length - 1;
    if (arr->length == arr->size)
        return;
    while (i >= 0 && x < arr->A[i])
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}

void isSorted(struct Array arr)
{
    bool issorted = true;
    for (int i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
        {
            issorted = false;
            cout << "no \n";
            break;
        }
    }
    if (issorted)
    {
        cout << "yes \n";
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void negative_to_left(struct Array *arr)
{
    int i = 0;
    int j = arr->length - 1;
    while (i < j)
    {
        while (arr->A[j] >= 0)
        {
            j--;
        }
        while (arr->A[i] < 0)
        {
            i++;
        }
        if (i < j)
            swap(&arr->A[i], &arr->A[j]);
    }
}
void Display(struct Array arr)
{
    for (int k = 0; k < arr.length; k++)
    {
        cout << arr.A[k] << " ";
    }
    cout << endl;
}
int main()
{
    struct Array arr{{1, 3, 4, 21, 33, 45, 47, 56}, 10, 8};
    // cout << sum_all(arr) << endl;
    // cout << max(arr) << endl;
    // cout << min(arr) << endl;
    // isSorted(arr);
    // rev(&arr);
    insert_sorted(&arr, 22);
    // negative_to_left(&arr);
    Display(arr);
    // left_shift(arr);
    return 0;
}