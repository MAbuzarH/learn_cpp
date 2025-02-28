#include <bits/stdc++.h>
using namespace std;

int main()
{
    int L, B, H;

    cout << "enter L: ";
    cin >> L;
    cout << "enter B: ";
    cin >> B;
    cout << "enter H: ";
    cin >> H;

    int ***arr = new int **[L];

    //
    for (int i = 0; i < L; i++)
    {
        // creating 2D array
        arr[i] = new int *[B];
        for (int j = 0; j < B; j++)
        {
            arr[i][j] = new int[H];
        }
    }

    for (int f = 0; f < L; f++)
    {
        for (int g = 0; g < B; g++)
        {
            for (int h = 0; h < H; h++)
            {
                cin >> arr[f][g][h];
            }
        }
    }

    cout << "the data is: \n";
    for (int l = 0; l < L; l++)
    {
        for (int m = 0; m < B; m++)
        {
            for (int n = 0; n < H; n++)
            {
                cout << arr[l][m][n] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // deletion
    for (int m = 0; m < L; m++)
    {

        for (int n = 0; n < B; n++) // my error correct is B
        {
            delete[] arr[m][n];
        }
        delete[] arr[m];
    }
    delete[] arr;
    cout << "deleted successfully" << endl;
    return 0;
}