#include <bits/stdc++.h>

using namespace std;

int sumofNum(int n)
{
    if (n < 0)
        return 0;

    // int sum;

    // sum = sumofNum(n - 1);

    // return (sum + n);
    return n + sumofNum(n - 1);
}

int main()
{
    int n = 3;
    cout << sumofNum(n);
    return 0;
}