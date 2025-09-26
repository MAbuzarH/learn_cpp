#include <iostream>
using namespace std;
class Dig
{
    int n;
    int *A;

public:
    Dig(int n)
    {
        this->n = n;
        A = new int[n];
    }
    void set(int i, int j, int x);
    void get(int i, int j);
    void dis()
    {
        delete[] A;
    }
    ~Dig();
};
void Dig::set(int i, int j, int x)
{
    if (i == j)
        A[i - 1] = x;
}
void Dig::get(int i, int j)
{
    if (i == j)
        cout << A[i - 1];
    else
        cout << "0";
}
void Dig::dis()
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i == j)
                cout << A[i - 1] << " ";
            else
                cout << "0" << " ";
        }
        cout << endl;
    }
}

int main()
{
    return 0;
}