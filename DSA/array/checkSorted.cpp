#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool result = true;
    int s = 5;
    int arr[s] = {1, 10, 5, 6, 7};
    for (int i = 1; i < s; i++)
    {
        if (arr[i] >= arr[i - 1])
        {
        }
        else
        {
            result = false;
        }
    }
    if (result)
    {
        cout << "sorted " << endl;
    }
    return 0;
}