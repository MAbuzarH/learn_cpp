#include <iostream>

using namespace std;

int main()
{

    int size = 5;
    int arr[size] = {10, 300, 4, 900, -2};
    int smallest = INT8_MAX;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }
    cout << "smallest number " << smallest << endl;
}