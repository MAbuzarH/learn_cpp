#include <iostream>
using namespace std;
struct Matrix
{
    int *A;
    int n; // dimention
};

// row major formula index([i][j]) = [i(i+1)/2]+j-1
void set(Matrix *m, int i, int j, int x)
{
    if (i <= j)
    {
        int index = ((i - 1) * m->n - (i - 2) * (i - i) / 2) + (j - i);
        m->A[index] = x;
    }
}

void get(Matrix m, int i, int j)
{
    if (i <= j)
    {
        int index = ((i - 1) * m.n - (i - 2) * (i - i) / 2) + (j - i);
        ;
        cout << m.A[index] << " \n";
    }
    else
    {
        cout << "0 \n";
    }
}
void dis(Matrix m)
{

    for (int i = 1; i <= m.n; i++)
    {
        for (int j = 1; j <= m.n; j++)
        {
            if (i <= j)
            {
                int index = ((i - 1) * m.n - (i - 2) * (i - i) / 2) + (j - i);
                cout << m.A[index] << " ";
            }
            else
                cout << "0 ";
        }
        cout << endl;
    }
}
int main()
{
    Matrix m;
    m.n = 5;
    // m.A = new int[m.n * ((m.n + 1) / 2)];
    m.A = new int[15];

    set(&m, 1, 1, 7);
    set(&m, 1, 2, 7);
    set(&m, 1, 3, 3);
    set(&m, 1, 4, 3);
    set(&m, 1, 5, 3);

    set(&m, 2, 2, 2);
    set(&m, 2, 3, 6);
    set(&m, 2, 4, 6);

    set(&m, 3, 3, 9);
    set(&m, 3, 4, 9);
    set(&m, 3, 5, 9);

    // set(&m, 4, 1, 8);
    // set(&m, 4, 2, 8);
    // set(&m, 4, 3, 8);
    set(&m, 4, 4, 8);
    set(&m, 4, 5, 8);
    // set(&m, 5, 1, 2);
    // set(&m, 5, 2, 2);
    // set(&m, 5, 3, 2);
    // set(&m, 5, 4, 2);
    set(&m, 5, 5, 2);
    get(m, 2, 5);
    dis(m);
    return 0;
}