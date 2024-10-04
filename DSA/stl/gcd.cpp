// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
    int num1 = 20;
    int num2 = 10;

    while (num1 > 0 && num2 > 0)
    {
        if (num1 > num2)
        {
            num1 = num1 % num2;
        }
        else
        {
            num2 = num2 % num1;
            
        }
        if (num1 == 0)
        {
            cout << "gcd " << num2 << endl;
        }
        else
        {
            cout << "gcd " << num1 << endl;
        }
    }
    return 0;
}

// void display(vector<int> &v)
// {
//     for (int i = 1; i < v.size(); i++)
//     {
//         cout << v[i] << " ";
//     }
//     cout << "\n"
//          << endl;
// }
//     vector<int> fec1;
//     vector<int> fec2;
//     int hcf;
//     for (int i = 1; i <= min(num1, num2); i++)
//     {
//         if (num1 % i == 0 && num2 % i == 0)
//         {
//             fec1.push_back(i);
//             hcf = i;
//         }
//     }
//     cout << hcf << endl;

//     display(fec1);
//     return 0;
// }

// #include <bits/stdc++.h>

// using namespace std;
// void display(vector<int> &v)
// {
//     for (int i; i < v.size(); i++)
//     {
//         cout << v[i] << " ";
//     }
//     cout << "\n"
//          << endl;
// }

// int main()
// {
//     int num1 = 20;
//     int num2 = 10;
//     vector<int> fec1;
//     vector<int> fec2;
//     int hcf;
//     for (int i = 1; i <= num2; i++)
//     {
//         if (num1 % i == 0 && num2 % i == 0)
//         {
//             fec1.push_back(i);
//         }
//     }

//     display(fec1);
//     return 0;
// }