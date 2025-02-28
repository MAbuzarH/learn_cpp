#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr{1, 2, 3, 1, 1, 1, 4, 2, 1, 3};
    int k = 3;
    int maxLength = 0;
    long long int sum = 0;
    map<long long, int> preSum;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            maxLength = max(maxLength, i + 1);
        }
        long long int rem = sum - k;
        if (preSum.find(rem) != preSum.end())
        {
            int len = i - preSum[rem];
            maxLength = max(maxLength, len);
        }
        if (preSum.find(sum) == preSum.end())
        {
            preSum[sum] = i;
        }
    }
    cout << "the max length: " << maxLength << endl;
}