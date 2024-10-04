#include <bits/stdc++.h>

using namespace std;

int main()
{
    // we can do this by converting number 
    //into string and then count its length
    //and then sapreate a number and a totalsum
    //increas this.
    int i = 371;
    int copy = i;
    int reverse = 0;
    int totalSum = 0;
    int numofdigit = 3;
    while (i != 0)
    {
        int ln = i % 10;
        totalSum += pow(ln,numofdigit);
        i = i / 10;
    }
    if (totalSum == copy)
    {
        cout << "number is armingstrom" << endl;
    }
    else
    {
        cout << "number is  not armingstrom" << endl;
    }
    return 0;
}