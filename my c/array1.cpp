//arrays
#include<iostream>
using namespace std;

int main() {
    int arr[100];
    int found = 2180;
    bool var = false;

    for(int i = 0; i < 100; i++) {
        arr[i] = i;
    }

    for(int j = 0; j < 100; j++) {
        if(arr[j] == found) {
            var = true;
            break; // Exit the loop when the value is found
        }
    }

    if(var == true) {
        cout << "Found" << endl;
    } else {
        cout << "Not found" << endl;
    }

    return 0;
}

