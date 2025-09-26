#include <iostream>
using namespace std;

struct Matrix
{
    int A[10];
    int n; // dimention
};

void set(Matrix *m, int i, int j, int x)
{
    if (i == j)
    {
        m->A[i - 1] = x;
    }
}
void get(Matrix m, int i, int j)
{
    if (i == j)
    {
        cout << m.A[i - 1] << "\n";
    }
    else
    {
        cout << "0 \n";
    }
}

void Dis(Matrix m)
{
    int i, j;
    for (i = 1; i <= m.n; i++)
    {
        for (j = 1; j <= m.n; j++)
        {
            if (i == j)
                cout << m.A[i - 1] << " ";
            else
                cout << "0" << " ";
        }
        cout << endl;
    }
}
int main()
{
    Matrix m;
    m.n = 4;
    set(&m, 1, 1, 1);
    set(&m, 2, 2, 4);
    set(&m, 3, 3, 8);
    set(&m, 4, 4, 7);
    // m.A[0] = 1;
    // m.A[1] = 3;
    // m.A[2] = 7;
    // m.A[3] = 9;
    Dis(m);
    return 0;
}
