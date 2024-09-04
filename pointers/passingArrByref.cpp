#include <iostream>
using namespace std;

void modifyArray(int (&arr)[5]) {
    for(int i = 0; i < 5; i++) {
        arr[i] *= 2;  // Double each element in the array
    }
}

int main() {
    int myArray[5] = {1, 2, 3, 4, 5};

    // Print the array before modification
    cout << "Before modification: ";
    for(int i = 0; i < 5; i++) {
        cout << myArray[i] << " ";
    }
    cout << endl;

    // Pass the array by reference to the function
    modifyArray(myArray);

    // Print the array after modification
    cout << "After modification: ";
    for(int i = 0; i < 5; i++) {
        cout << myArray[i] << " ";
    }
    cout << endl;

    return 0;
}

