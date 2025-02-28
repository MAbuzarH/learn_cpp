#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr{1, 2, 3, 1, 1, 1, 2, 2, 1, 2, 1, 3};
    long long int sum = arr[0];
    int maxLength = 0;
    int left = 0, right = 0;
    int n = arr.size();
    int k = 8;

    while (right < n)
    {

        while (left <= right && sum > k)
        {
            sum -= arr[left];
            left++;
        }

        if (sum == k)
        {
            maxLength = max(maxLength, right - left + 1);
        }
        right++;
        if (right < n)
        {
            sum += arr[right];
        }
    }
    cout << "max length: " << maxLength << endl;

    return 0;
}