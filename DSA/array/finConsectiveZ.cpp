#include <bits/stdc++.h>

using namespace std;

int main()
{
    int cnt = 0;
    int max = 0;
    vector<int> nums{1, 1, 0, 1};

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            cnt++;
        }
        else
        {
            if (cnt > max)
            {
                max = cnt;
            }
            cnt = 0;
        }
    }

    cout << max;
    return 0;
}