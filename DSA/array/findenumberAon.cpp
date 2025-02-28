#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums{1, 1, 2, 3, 3, 4, 4};
    
    for (int i = 0; i < nums.size(); i++)
    {
        int cnt = 0;  // Reset cnt for each number
        int num = nums[i];

        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] == num)
            {
                cnt++;
            }
        }

        if (cnt == 1)
        {
            cout << num << " appears " << cnt << " time.\n";
        }
    }

    return 0;
}



// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     vector<int> nums{1, 1, 2, 3, 3, 4, 4};
//     int cnt = 0;
//     int num = 0;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         num = nums[i];

//         for (int j = 0; j < nums.size(); j++)
//         {

//             if (nums[j] == num)
//             {

//                 cnt++;
//             }
//         }

//        if (cnt == 1){
//         cout << cnt;
//        }
//     }

//     return 0;
// }