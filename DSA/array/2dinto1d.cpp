#include <iostream>
using namespace std;

int main()
{
    int rows, cols;

    cout << "Enter the number of rows and columns:";
    cin >> rows >> cols;
    int siz = rows * cols;

    int *arr = new int[siz];

    cout << "Enter The data  \n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int index = i * cols + j; // Mapping from 2D (i, j) to 1D
            cout << "Enter value for (" << i << "," << j << "): ";
            cin >> arr[index];
        }
    }

    cout << "Out put \n";
    for (int l = 0; l < rows; l++)
    {
        for (int k = 0; k < cols; k++)
        {
            int Oindex = l * cols + k;
            cout << arr[Oindex] << " ";
        }
        cout << "\n";
    }

    delete[] arr;
}