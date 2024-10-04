#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abcabdefdef";

    int hash[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i] - 'a']++;
    }
    int q;
    cout << "how many qures you have " << endl;
    cin >> q;
    while (q--)
    {
        char c;
        cout << "Enter char \n";
        cin >> c;
        cout << c << " : " << hash[c - 'a'] << endl;
    }

    return 0;
}