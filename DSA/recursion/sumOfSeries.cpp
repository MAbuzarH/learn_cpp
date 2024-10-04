#include <bits/stdc++.h>
using namespace std;

long long sumOfSeries(long long int n)
{
    // code here
    if (n <= 0)
    {
        return 0;
    }
    long long int sum = 0;
    sum = sumOfSeries(n - 1);

    return sum + (n * n * n);
}

int main()
{
    long long int n = 5;
    cout << sumOfSeries(n);

    return 0;
}