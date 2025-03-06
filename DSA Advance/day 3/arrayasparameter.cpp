#include <iostream>
using namespace std;

int fun(int A[])
{
    for (int i = 0; i < 5; i++)
    {
        A[i] = i + 2;
        cout << A[i] << endl;
    }
    // cout << sizeof(A) / sizeof(int) << endl;
}
int main()
{
    int A[] = {1, 2, 3, 4, 5};
    int n = 5;
    fun(A);
    // cout << sizeof(A) / sizeof(int) << endl;
    for (int x : A)
    {
        cout << " " << x;
    }
}