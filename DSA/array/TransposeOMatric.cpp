#include <bits/stdc++.h>
using namespace std;

int main()
{
    int row, col;

    cout << "Enter the number of rows: ";
    cin >> row;
    cout << "Enter the number of col: ";
    cin >> col;
    int **m1 = new int *[row];
    int rrow = col;
    int rcol = row;
    int result[rrow][rcol];
    for (int i = 0; i < row; i++)
    {
        m1[i] = new int[col];
    }

    cout << "Enter the data of m1: \n";
    for (int j = 0; j < row; j++)
    {
        for (int k = 0; k < col; k++)
        {
            cin >> m1[j][k];
        }
    }

    for (int f = 0; f < rrow; f++)
    {
        for (int h = 0; h < rcol; h++)
        { // 0 //2     //2//0
            result[f][h] = m1[h][f];
        }
        cout << endl;
    }

    cout << "Out put is: \n";

    for (int z = 0; z < rrow; z++)
    {
        for (int y = 0; y < rcol; y++)
        {
            cout << result[z][y] << " ";
        }
        cout << endl;
    }

    // delete data for m1;
    for (int d = 0; d < row; d++)
    {
        delete[] m1[d];
    }
    delete[] m1;
    return 0;
}