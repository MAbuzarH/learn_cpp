#include <iostream>
#include <vector>
#include <algorithm> // For sort()
#include <chrono>    // For high-resolution clock
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()// For time()
using namespace std;
using namespace std::chrono;
// Function to generate a random array of size n
vector<int> generateRandomArray(int n)
{
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100000; // Random numbers between 0 and 99,999
    }
    return arr;
}
// Linear Search function
int linearSearch(const vector<int> &arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}
// Binary Search function
int binarySearch(const vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
// Main function to measure performance of both algorithms
int main()
{
    srand(time(0)); // Seed for random number generator
    int n;          // Size of the array
    cout << "Enter the size of the array: ";
    cin >> n;
    // Generate a random array
    vector<int> arr = generateRandomArray(n);
    // Target element to search
    int target = rand() % 100000;
    // Measure the time for Linear Search
    auto start_linear = high_resolution_clock::now();
    int result_linear = linearSearch(arr, target);
    auto stop_linear = high_resolution_clock::now();
    auto duration_linear = duration_cast<microseconds>(stop_linear - start_linear);
    cout << "Linear Search Time: " << duration_linear.count() << " microseconds" << endl;
    // Sort the array for Binary Search (required for binary search to work)
    sort(arr.begin(), arr.end());
    // Measure the time for Binary Search
    auto start_binary = high_resolution_clock::now();
    int result_binary = binarySearch(arr, target);
    auto stop_binary = high_resolution_clock::now();
    auto duration_binary = duration_cast<microseconds>(stop_binary - start_binary);
    cout << "Binary Search Time: " << duration_binary.count() << " microseconds" << endl;
    // Output search results (optional)
    if (result_linear != -1)
    {
        cout << "Linear Search: Target found at index " << result_linear << endl;
    }
    else
    {
        cout << "Linear Search: Target not found" << endl;
    }
    if (result_binary != -1)
    {
        cout << "Binary Search: Target found at index " << result_binary << endl;
    }
    else
    {
        cout << "Binary Search: Target not found" << endl;
    }
    return 0;
}
