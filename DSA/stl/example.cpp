
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    int x = 10;

    string reverse;
    string copy = to_string(x);

    int n = copy.length();
    for (int i = 0; i <= n + 1; i++)
    {
        // reverse[i] =
        cout << copy[n];
        // cout << n << endl;
        n--;
    }
    // cout << reverse << endl;
    // cout << copy << endl;
    // if (reverse.compare(copy))
    // {
    //     cout << "true" << endl;
    // }
    // cout << "false" << endl;
    // int reverse = 0;
    // string copy = to_string(x);
    // while (x != 0)
    // {
    //     int num = x % 10;
    //     if (reverse > (INT_MAX / 10) || (reverse == (INT_MAX / 10) && num > 7))
    //     {
    //         return 0; // Overflow condition
    //     }
    //     if (reverse < (INT_MIN / 10) || (reverse == (INT_MIN / 10) && num < -8))
    //     {
    //         return 0; // Underflow condition
    //     }
    //     cout << "num in loop" << num << endl;
    //     reverse = num + (reverse * 10);
    //     x = x / 10;
    // }
    // if (copy == to_string(reverse))
    // {
    //     // return true;
    //     cout << "real" << copy << endl;
    //     cout << "copy" << reverse << endl;
    // }
    // cout << "real" << copy << endl;
    // cout << "copy" << reverse << endl;
    //    return false;

    return 0;
}

// pair<int, int> p{1, 2};
// pair<int, pair<int,int>> p{1, {2,3}};
// cout << p.first << " " << p.second.second;
// stack<int> a;
// queue<int> q;
// for (int i = 1; i <= 5; i++)
// {
//     a.push(i);
//     q.push(i);
// }
// cout << a.top();
// cout << q.front();
//  int a = 1534236469;
// cout << a << endl;
// int revers = 0;
// while (a != 0)
// {
//     int num = 0;
//     num = a % 10;
//     if (revers > (INT_MAX / 10) || (revers == (INT_MAX / 10) && num > 7))
//     {
//         return 0; // Overflow condition
//     }
//     if (revers < (INT_MIN / 10) || (revers == (INT_MIN / 10) && num < -8))
//     {
//         return 0; // Underflow condition
//     }
//     revers = num + (revers * 10);
//     a = a / 10;
// }
// // revers = revers * 10;
// cout << revers << endl;

// int copy = a;
// int count = 0;
// while (a != 0)
// {

//     int num = a % 10;
//     a = a / 10;
//     if (num == 0)
//         continue;
//     if (copy % num == 0)
//     {
//         count++;
//     }
// }
// cout << count;
// int first = a % 10; // 4
// a = a / 10;
// int second = a % 10;
// cout << a % 10;
