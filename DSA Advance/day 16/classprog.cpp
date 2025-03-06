#include <iostream>
using namespace std;

class Array
{
private:
    int *p;
    int length;
    int size;
    void Swap(int *a, int *b);

public:
    // constrcture
    Array()
    {
        size = 10;
        length = 0;
        p = new int[size];
    };
    Array(int sz)
    {
        size = sz;
        length = 0;
        p = new int[size];
    }

    void Append(int value);
    void Insert(int index, int value);

    int Linearsearch(int key);
    int Binarysearch(int key);
    // int Rbsearch(int key);
    int Get(int index);
    void Set(int index, int value);
    int Max();
    int Min();
    int Sum();
    float Avrage();
    void Reverse();
    void Reverse2();
    void Insert_in_sorted(int value);
    int Issorted();
    void Rearrange();
    int Delete(int Index);
    Array *Marge(Array arr2);
    Array *Union(Array arr2);
    Array *Intersec(Array arr2);
    Array *Diffrence(Array arr2);

    void Display();

    ~Array()
    {
        delete[] p;
    }
};
int Array::Binarysearch(int key)
{
    for (int i = 0; i < length; i++)
    {
        if (p[i] == key)
        {
            return i;
        }
    }
    return -1;
}
Array *Array::Marge(Array arr2)
{
    int i = 0, j = 0, k = 0;
    Array *arr3 = new Array(length + arr2.length);
    while (i < length && j < arr2.length)
    {
        if (p[i] < arr2.p[j])
        {
            arr3->p[k++] = p[i++];
        }
        else if (arr2.p[j] < p[i])
        {
            arr3->p[k++] = arr2.p[j++];
        }
        else
        {
            arr3->p[k++] = arr2.p[j++];
            i++;
        }
    }
    for (; i < length; i++)
    {
        arr3->p[k++] = p[i];
    }
    for (; j < arr2.length; j++)
    {
        arr3->p[k++] = arr2.p[j];
    }
    arr3->length = length + arr2.length;
    return arr3;
}

void Array::Insert_in_sorted(int value)
{
    if (length < size)
    {
        int i = length - 1;
        while (i >= 0 && p[i] > value)
        {
            p[i + 1] = p[i];
            i--;
        }
        // for (i = length; i >= 0; i--)
        // {
        //     if (p[i] < value)
        //     {
        //         break;
        //     }
        // }

        p[i + 1] = value;
        length++;
    }
}
void Array::Reverse2()
{
    int *arrtemp;
    arrtemp = new int[length];
    int i = 0, j = length - 1;
    for (; i < length; i++)
    {
        arrtemp[i] = p[j];
        j--;
    }
    for (int k = 0; k < length; k++)
    {
        p[k] = arrtemp[k];
    }
}

void Array::Reverse()
{
    int i = 0, j = length - 1;
    for (; i < j; i++, j--)
    {
        Swap(&p[i], &p[j]);
    }
}

float Array::Avrage()
{
    return (float)Sum() / length;
}

int Array::Sum()
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += p[i];
    }
    return sum;
}

int Array::Min()
{
    int min = p[0];
    for (int i = 1; i < length; i++)
    {
        if (p[i] < min)
        {
            min = p[i];
        }
    }
    return min;
}

int Array::Max()
{
    int max = p[0];
    for (int i = 1; i < length; i++)
    {
        if (p[i] > max)
        {
            max = p[i];
        }
    }
    return max;
}

void Array::Set(int index, int value)
{
    p[index] = value;
}
int Array::Get(int index)
{
    return p[index];
}

int Array::Issorted()
{
    for (int i = 0; i < length; i++)
    {
        if (p[i] > p[i + 1])
        {
            return 0;
        }
    }
    return 1;
}
void Array::Append(int value)
{
    if (length < size)
    {
        p[length++] = value;
    }
}
void Array::Insert(int index, int value)
{
    int i;
    if (index >= 0 && index < length)
    {
        for (i = length; i > index; i--)
        {
            p[i] = p[i - 1];
        }
        p[index] = value;
        length++;
    }
}

int Array::Delete(int index)
{
    int x = p[index];
    if (index <= length && index >= 0)
    {
        for (int i = index; i <= length - 1; i++)
        {
            p[i] = p[i + 1];
            length--;
        }
        return x;
    }
}
void Array::Swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void Array::Display()
{
    printf("Array elements are:\n");
    for (int i = 0; i < length; i++)
    {
        cout << p[i] << " ";
    }
}
int main()
{
    Array *arr;
    int ch, sz, x, index;
    cout << "enter the size of the array" << endl;
    cin >> sz;
    arr = new Array(sz);

    do
    {
        cout << "\n\nMenu\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Sum\n";
        cout << "5. Display\n";
        cout << "6.Exit\n";

        cout << "enter you choice ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter an element and  index ";
            cin >> x >> index;
            arr->Insert(index, x);
            break;
        case 2:
            cout << "Enter index ";
            cin >> index;
            x = arr->Delete(index);
            cout << "Deleted Element is" << x;
            break;
        case 3:
            cout << "Enter element to search ";
            cin >> x;
            index = arr->Binarysearch(x);
            cout << "Element index " << index;
            break;
        case 4:
            cout << "Sum is " << arr->Sum();
            break;
        case 5:
            arr->Display();
        }
    } while (ch < 6);
    arr->Display();
    return 0;
}