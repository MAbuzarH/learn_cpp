#include <bits/stdc++.h>

using namespace std;

int main()
{
    int C, M, D;
    cout << "How many cities data You want to store: ";
    cin >> C;
    cout << "How many Months data You want to store: ";
    cin >> M;
    cout << "How many  data You want to store: ";
    cin >> D;

    int ***table = new int **[C];

    for (int i = 0; i < C; i++)
    {
        table[i] = new int *[M];
        for (int j = 0; j < D; j++)
        {
            table[i][j] = new int[D];
        }
    }

    cout << " enter the temperature data \n";

    for (int k = 0; k < C; k++)
    {
        for (int l = 0; l < M; l++)
        {
            for (int m = 0; m < D; m++)
            {
                cin >> table[k][l][m];
            }
        }
    }
    cout << "out put \n";
    for (int n = 0; n < C; n++)
    {
        cout << "Data of city" << n + 1 << endl;
        for (int o = 0; o < M; o++)
        {
            cout << "Data of Month" << o + 1 << endl;
            for (int p = 0; p < D; p++)
            {
                cout << table[n][o][p] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    for (int q = 0; q < C; q++)
    {
        for (int r = 0; r < M; r++)
        {
            delete[] table[q][r];
        }
        delete[] table[q];
    }

    delete[] table;
    table = NULL;
    cout << "Table :" << table;
    return 0;
}
// for (int k = 0; k < C; k++)
// {
//     for (int l = 0; l < M; l++)
//     {
//         for (int m = 0; m < D; m++)
//         {
//             cin >> table[C][M][D];
//         }
//     }
// }