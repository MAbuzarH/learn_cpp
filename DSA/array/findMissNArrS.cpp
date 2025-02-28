#include <bits/stdc++.h>

using namespace std;

int main()
{
    // this is the optimal ;
    int n = 5;
    vector<int> vec{2, 3, 4, 5};
    int size = vec.size();
    // cout << size << endl;
    // int sum = size * (size + 1) / 2;
    int sum = 0;
    int totalsumTilN = n * (n + 1) / 2;
    // for (int i = 1; i <= n; i++)
    // {
    //     totalsumTilN += i;
    // }
    cout << totalsumTilN << endl;
    for (int j = 0; j < vec.size(); j++)
    {
        sum += vec[j];
    }
    cout << sum << endl;
    int mising = totalsumTilN - sum;
    cout << mising << endl;
    return 0;
}