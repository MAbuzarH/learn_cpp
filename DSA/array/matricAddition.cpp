#include <bits/stdc++.h>
using namespace std;
int main()
{
    int rowm1, colm1, rowm2, colm2, rowm3, colm3;
    cout << "Enter the number of rows of m3 reseultent:";
    cin >> rowm3;
    cout << "Enter the number of columns  of m3 reseultent:";
    cin >> colm3;
    cout << "Enter the number of rows of m1 :";
    cin >> rowm1;
    cout << "Enter the number of columns  of m1:";
    cin >> colm1;

    int **m1 = new int *[rowm1];
    int **m2 = new int *[rowm2];
    int **m3 = new int *[rowm3];
    // create an array for m1
    for (int i = 0; i < rowm1; i++)
    {
        m1[i] = new int[colm1];
    }
    // create an array for m3
    for (int x = 0; x < rowm3; x++)
    {
        m3[x] = new int[colm3];
    }

    cout << "enter row and colom data for M1" << endl;
    for (int a = 0; a < rowm1; a++)
    {
        for (int b = 0; b < colm1; b++)
        {
            cin >> m1[a][b];
        }
    }

    cout << "Enter the number of rows of m2 :";
    cin >> rowm2;
    cout << "Enter the number of columns  of m2:";
    cin >> colm2;

    // create an array for m2
    for (int j = 0; j < rowm2; j++)
    {
        m2[j] = new int[colm2];
    }

    cout << "enter row and colom data for M2" << endl;
    for (int e = 0; e < rowm2; e++)
    {
        for (int f = 0; f < colm2; f++)
        {
            cin >> m2[e][f];
        }
    }

    // functionality

    for (int k = 0; k < rowm1; k++)
    {
        for (int l = 0; l < colm1; l++)
        {
            m3[k][l] = m1[k][l] + m2[k][l];
        }
    }

    // print result
    cout << "Result of addition" << endl;
    for (int m3i = 0; m3i < rowm1; m3i++)
    {
        for (int m3j = 0; m3j < colm1; m3j++)
        {
            cout << m3[m3i][m3j] << " ";
        }
        cout << endl;
    }
    // delete data for m1;
    for (int d = 0; d < rowm1; d++)
    {
        delete[] m1[d];
    }
    // delete data for m2;
    for (int z = 0; z < rowm2; z++)
    {
        delete[] m2[z];
        delete[] m3[z];
    }
    delete[] m1;
    delete[] m2;
    delete[] m3;
    m1 = NULL;
    m2 = NULL;
    m3 = NULL;
    return 0;
}