#include <iostream>
using namespace std;
int main()
{
    int passed = 0;
    int falied = 0;
    int student = 1;
    int result = 0;

    while (student <= 10)
    {
        cout << "enter result for student:" << student;
        cin >> result;
        if (result == 1)
        {
            passed++;
        }
        if (result == 2)
        {
            falied++;
        }
        student++;
    }

    if (passed >= 8)
    {
        cout << "bounos\n";
    }

    cout << "passed: " << passed << " \n " << "failed: " << falied << "\n";
    return 0;
}