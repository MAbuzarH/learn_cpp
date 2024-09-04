#include <iostream>
#include <string>

using namespace std;

int main()
{
    // int a = 50, b = 10, c = 20;
    // if (a < b && c > b)
    // {
    //     cout << "middel number is" << b << endl;
    // }
    // else if (b < a && c > a)
    // {
    //     cout << "middel number is" << a << endl;
    // }
    // else
    // {
    //     cout << "middel number is" << c << endl;
    // }
    // int a = 50, b = 10, c = 20;

    // if ((a >= b && a <= c) || (a <= b && a >= c))
    // {
    //     cout << "Middle number is " << a << endl;
    // }
    // else if ((b >= a && b <= c) || (b <= a && b >= c))
    // {
    //     cout << "Middle number is " << b << endl;
    // }
    // else
    // {
    //     cout << "Middle number is " << c << endl;
    // }

    // string yourFName = "Abuzar";
    // string yourLName = "Haider";
    // cout << "enter your name" << endl;
    // getline(cin, yourName);
    // cout << "your name" << yourName << endl;
    // cout << "first element of your name: " << yourFName.at(0) << endl;
    // cout << "first element of your name: " << yourLName.at(yourLName.size() - 1) << endl;

    // ==============  Task 1 =================
    int wordCount = 0;
    int spaceCount = 0;
    string a = "hi ali";
    //    cout<<a.length()<<endl;
    //    cout<<a.size() << endl;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == 32)
        {
            spaceCount++;
        }
        else
        {
            wordCount++;
        }
    }
    cout << spaceCount << " : " << wordCount << endl;

    // ============ Task 2  =================
    // check if the string is Palindrome

    string b = "1";
    char first = b.at(0);
    char last = b.at(b.size() - 1);
    if (first == last)
    {
        cout << "Palindrome" << endl;
    }

  // ============ Task 3  =================
    

    return 0;
}