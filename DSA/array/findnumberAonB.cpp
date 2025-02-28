#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr{1, 1, 2, 2, 3, 4, 4, 5, 5};
    unordered_map<int, int> Mymap;

    for (int i = 0; i < arr.size(); i++)
    {
        Mymap[arr[i]]++;
    }
   unordered_map<int, int>::iterator it = Mymap.begin();
    while (it != Mymap.end())
    {
        if (it->second == 1)
        {
            cout << "one time: " << it->first << endl;
        }
        it++;
    }
    return 0;
}