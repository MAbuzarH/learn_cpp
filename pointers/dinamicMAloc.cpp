#include <iostream>

using namespace std;

int main()
{
    // // createing one var by dinamic Memory allocation;
    // int *ptr{nullptr};
    // ptr = new int;
    // cout<<ptr <<" "<< *ptr <<endl;
    // *ptr = 500;
    // cout<<ptr <<" "<< *ptr <<endl;
    // delete ptr;
    // createing array by dinamic Memory allocation;
    int size;
    cout << "How big do you want to allocate?" << endl;
    cin >> size;

    int *arr_ptr = NULL; // Initialize the pointer to nullptr
    arr_ptr = new int[size]; // Dynamically allocate memory for the array

    for (int i = 0; i < size; i++) {
        arr_ptr[i] = i + 3; // Initialize array elements
    }

    for (int j = 0; j < size; j++) {
        cout << arr_ptr[j] << endl; // Print array elements
    }

    delete[] arr_ptr; // Deallocate the memory
    arr_ptr = NULL; // Set pointer to nullptr after deletion to avoid dangling pointer

    return 0;
    }
