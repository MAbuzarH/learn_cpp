#include <iostream>
using namespace std;

int main()
{
    int sz = 10;
    int arr[sz] = {1, 2, 3, 5, 6, 7, 8, 9, 10, 11};
    int sum = 0;
    for (int i = 0; i < sz; i++)
    {
        sum += arr[i];
    }
    int n = arr[sz - 1];
    int mb = (n * (n + 1)) / 2;
    cout << mb << "\n"
         << n << endl;
    cout << "missing: " << mb - sum << endl;

    return 0;
}