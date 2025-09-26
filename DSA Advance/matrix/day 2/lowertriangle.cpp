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
    if (i >= j)
    {
        int index = (i * (i - 1) / 2) + (j - 1);
        m->A[index] = x;
    }
}

void get(Matrix m, int i, int j)
{
    if (i >= j)
    {
        int index = (i * (i - 1) / 2) + (j - 1);
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
            if (i >= j)
            {
                int index = (i * (i - 1) / 2) + (j - 1);
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

    set(&m, 1, 1, 3);

    set(&m, 2, 1, 2);
    set(&m, 2, 2, 6);

    set(&m, 3, 1, 9);
    set(&m, 3, 2, 9);
    set(&m, 3, 3, 9);

    set(&m, 4, 1, 8);
    set(&m, 4, 2, 8);
    set(&m, 4, 3, 8);
    set(&m, 4, 4, 8);
    set(&m, 5, 1, 2);
    set(&m, 5, 2, 2);
    set(&m, 5, 3, 2);
    set(&m, 5, 4, 2);
    set(&m, 5, 5, 2);
    get(m, 1, 1);
    dis(m);
    return 0;
}