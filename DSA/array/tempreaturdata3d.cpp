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
                cin >> table[C][M][D];
            }
        }
    }
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
    cout<<"out put ";
    return 0;
}