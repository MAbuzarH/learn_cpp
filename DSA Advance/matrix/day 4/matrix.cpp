#include <iostream>
using namespace std;

int main()
{
    int *A, n, ch, x, i, j;
    cout << "Enter dimentions \n";
    cin >> n;
    A = new int[n];
    do
    {
        cout << "1: create A matrix \n";
        cout << "2: Get any element from matrix \n";
        cout << "3: Set any element in matrix \n";
        cout << "4: display A matrix \n";
        cout << "5: Exit \n";
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1: // Create diagonal matrix
            cout << "Enter " << n << " elements (one by one):\n";
            for (i = 1; i <= n; i++)
            {
                cin >> A[i - 1];
            }
            break;
        case 2: // Get element
            cout << "Enter indices i and j: ";
            cin >> i >> j;
            if (i >= 1 && j >= 1 && i <= n && j <= n)
            {
                cout << "Value: " << (i == j ? A[i - 1] : 0) << endl;
            }
            else
            {
                cout << "Invalid indices!\n";
            }
            break;
        case 3:

            cout << "Enter element index i,j  and value\n";
            cin >> i >> j >> x;
            if (i == j)
            {
                A[i - 1] = x;
            }
            break;
        case 4: // Display matrix
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n; j++)
                {
                    cout << (i == j ? A[i] : 0) << " ";
                }
                cout << endl;
            }
            break;

        case 5: // Exit
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (ch != 5);
    delete[] A;
    return 0;
}