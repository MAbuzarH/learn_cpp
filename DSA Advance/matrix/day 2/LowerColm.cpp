#include <iostream>
using namespace std;
struct Matrix
{
    int *A;
    int n; // dimention
};

// colum major formula index([i][j]) = [i(i-1)/2]+j-1
void set(Matrix *m, int i, int j, int x)
{
    if (i >= j)
    {
        cout << "set \n";
        int index = m->n * (j - 1) - (j - 2) * (j - 1) / 2 + i - j;
        m->A[index] = x;
    }
}

void get(Matrix m, int i, int j)
{
    if (i >= j)
    {
        int index = m.n * (j - 1) - (j - 2) * (j - 1) / 2 + i - j;
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
                int index = m.n * (j - 1) -
                            (j - 2) * (j - 1) / 2 + i - j;
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
    m.n = 2;
    set(&m, 1, 1, 1);
    set(&m, 2, 1, 1);
    set(&m, 2, 2, 2);
    get(m, 1, 2);

    // int die, i, j, x;
    // cout << "enter dimentions \n";
    // cin >> die;
    // m.n = die;
    // cout << "enter all element \n";
    // for (i = 1; i <= m.n; i++)
    // {
    //     for (j = 1; j <= m.n; j++)
    //     {
    //         cin >> x;
    //         set(&m, i, j, x);
    //     }
    // }
    // cout << "\n \n";
    // cout << "\nMatrix representation:\n";
    // dis(m);

    // Free allocated memory
    delete[] m.A;
    return 0;
}