#include <bits/stdc++.h>

using namespace std;

int main()
{
    // 1 3 5 8 9 2 6 7 6 8 9
    //1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9
    int arr[] = {1, 4, 3, 2, 6, 7};
    int value = arr[0];
    int size = sizeof(arr) / sizeof(arr[0]);
    int jump = 0;
    if (arr[0] == 0)
    {
        return -1;
    }

    for (int i = 0; i < size; i++)
    {

        if (value == i)
        {
            value = arr[i];
            for (int j = i; j < value; j++)
            {
                // int max = arr[i+j];
                if (value < arr[j])
                {
                    value = arr[j];
                }
            }
            ++jump;
           
        }
    }
    cout << jump << endl;
    return 0;
}