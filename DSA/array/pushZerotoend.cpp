#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v{1, 2, 3, 2, 0, 0, 4, 0, 0, 0, 8, 4, 0, 5};
    vector<int> temp;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != 0)
        {
            temp.push_back(v[i]);
        }
    };

    for (int j = 0; j < temp.size(); j++)
    {
        v[j] = temp[j];
    }
    int count = v.size() - temp.size();

    for (int k = v.size() - count; k <= v.size(); k++)
    {
        v[k] = 0;
    }
    for (int l = 0; l < v.size(); l++)
    {
        cout << v[l] << " ";
    }

    return 0;
}
