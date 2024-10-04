#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<char, int> mapp;

    string s = "abcdefadds";
    for (int i = 0; i < s.size(); i++)
    {
        mapp[s[i]]++;
    }
    int q;
    cout << "how many queries you have:";
    cin >> q;
    while (q--)
    {
        char a;
        cout << "enter query:";
        cin >> a;
        cout << a << ":" << mapp[a] << "\n";
    }
    return 0;
}