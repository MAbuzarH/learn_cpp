#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x = 1000000001;
    if (x > (INT_MAX / 10) || (x == (INT_MAX / 10) && x > 7))
    {
        return 0; // Overflow condition
    }
    if (x < (INT_MIN / 10) || (x == (INT_MIN / 10) && x < -8))
    {
        return 0; // Underflow condition
    }
    string reverse;
    string copy = to_string(x);
    int s = copy.size();
    int n = s;
    for (int i = 0; i < s; i++)
    {
        reverse += copy[n - 1];
        --n;
    }
    cout << reverse;
    if (reverse == copy)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}