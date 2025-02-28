#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k = 3; // Target sum
    vector<int> arr{1, 2, 1, 1, 1, 4, 3, 1};
    int sum;
    int lng = 0;

    // Loop over all starting points
    for (int i = 0; i < arr.size(); i++)
    {
        sum = 0; // Reset sum for each new starting point

        // Loop over all subarrays starting at i
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j]; // Add current element to sum

            if (sum == k)
            {
                // Update the maximum length of subarray with sum == k
                lng = max(lng, j - i + 1);
            }
        }
    }

    cout << "Longest subarray length with sum " << k << " is: " << lng << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int k = 3;
//     vector<int> arr{1, 2, 1, 1, 1, 4, 3, 1};
//     int sum;
//     int lng = 0;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         for (int j = i; j < arr.size(); j++)
//         {
//             sum = 0;
//             for (int l = i; l < j; l++)
//             {
//                 sum += arr[l];
//                 if (sum == k)
//                 {
//                     lng = max(lng, j - i + 1);
//                 }
//             }
//         }
//     }
//     cout << lng;
//     return 0;
// }