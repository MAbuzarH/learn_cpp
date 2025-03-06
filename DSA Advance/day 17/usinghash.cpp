#include <iostream>
using namespace std;
int max(int arr[], int s)
{
    int m = arr[0];
    for (int i = 1; i < s; i++)
    {
        if (m < arr[i])
        {
            m = arr[i];
        }
    }
    return m;
}
int main()
{
    int sz = 9;
    int arr[sz] = {6, 7, 8, 9, 12, 1, 3, 5, 4};
    int Hs = max(arr, sz);
    cout << Hs << endl;
    int *H;
    H = new int[Hs];
    int j = 0;
    for (int o = 0; o < Hs; o++)
    {
        H[o] = 0;
    }
    for (int i = 0; i <= Hs; i++)
    {

        if (j < sz)
        {
            H[arr[j]] = 1;
            j++;
        }
        else
        {
            break;
        }
    }
    for (int k = 1; k < Hs; k++)
    {
        if (H[k] == 0)
        {
            cout << "Number is missing: " << k << endl;
        }
    }

    return 0;
}