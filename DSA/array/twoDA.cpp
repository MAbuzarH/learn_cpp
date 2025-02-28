#include <bits/stdc++.h>

using namespace std;

// table[1][2] = 88;
// cout << table[1][2];

int main()
{
    int row, column;
    cout << "Enter the number of rows: " << endl;
    cin >> row;
    cout << "Enter the number of c: " << endl;
    cin >> column;

    // step 1 create a pointer to pointer that pointes array of pointers
    int **table = new int *[row];

    // step 3
    for (int i = 0; i < row; i++)
    {
        table[i] = new int[column];
    }

    // get data
    cout << "enter data  on table[row][column] \n";
    for (int k = 0; k < row; k++)
    {
        for (int l = 0; l < column; l++)
        {
            cin >> table[k][l];
        }
    }

    // print data
    for (int a = 0; a < row; a++)
    {
        for (int b = 0; b < column; b++)
        {
            cout << table[a][b] <<" ";
        }
        cout << endl;
    }

    // as pr rule if we alocate memory we must dealocat it
    for (int j = 0; j < row; j++)
    {
        // delete the memory which table[i] points to
        delete[] table[j];
    }

    // last step delete table
    delete[] table;
    // after proforming the above step we delete the memory
    // so it is not good to have address of freed memory
    // so poin table to null;
    table = NULL;
    return 0;
}