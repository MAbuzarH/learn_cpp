#include <iostream>
using namespace std;
int main()
{
    int i, j, sz = 10;
    int t = 0;
    int arr[sz] = {1, 2, 8, 8, 9, 10, 15, 15, 15, 16};
    for (i = 0; i < sz; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            j = i + 1;
            while (arr[j] == arr[i])
                j++;
            printf("%d repetes %d times. \n", arr[i], j - i);
            t += j - i;
            i = j - 1;
        }
    }
    cout << t;
}