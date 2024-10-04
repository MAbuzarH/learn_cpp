#include <bits/stdc++.h>

using namespace std;
                              //l      m      //r
void marge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    //lp
    int right = mid + 1;
    //rp
    int left = low;
    int i = 0;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);

            left++;
        }
        else
        {
            temp.push_back(arr[right]);

            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int j = low; j <= high; j++)
    {
        arr[j] = temp[j - low];
    }
}

void marge_sort(vector<int> &arr, int low, int high)
{
    // base case
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    marge_sort(arr, low, mid);
    marge_sort(arr, mid + 1, high);
    marge(arr, low, mid, high);
}

int main()
{

    int s = 6;
    vector<int> arr{3, 2, 4, 7, 10, 1};
    int low = 0;
    int high = arr.size() - 1;
    marge_sort(arr, low, high);
    for (int k = 0; k < s; k++)
    {
        cout << arr[k] << " ";
    }
    return 0;
}