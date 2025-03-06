#include <iostream>
using namespace std;

int main() {
    int L = 2, B = 3, H = 4, W = 5; // Dimensions

    // Dynamically create a 4D array
    int ****arr = new int***[L];

    for (int i = 0; i < L; i++) {
        arr[i] = new int**[B];
        for (int j = 0; j < B; j++) {
            arr[i][j] = new int*[H];
            for (int k = 0; k < H; k++) {
                arr[i][j][k] = new int[W];
            }
        }
    }

    // Fill the array with values (optional, just for demonstration)
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < B; j++) {
            for (int k = 0; k < H; k++) {
                for (int l = 0; l < W; l++) {
                    arr[i][j][k][l] = i + j + k + l; // Arbitrary formula for values
                }
            }
        }
    }

    // Print the array values
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < B; j++) {
            for (int k = 0; k < H; k++) {
                for (int l = 0; l < W; l++) {
                    cout << "arr[" << i << "][" << j << "][" << k << "][" << l << "] = " << arr[i][j][k][l] << endl;
                }
            }
        }
    }

    // Clean up the dynamically allocated memory
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < B; j++) {
            for (int k = 0; k < H; k++) {
                delete[] arr[i][j][k]; // Delete 1D array
            }
            delete[] arr[i][j]; // Delete 2D array
        }
        delete[] arr[i]; // Delete 3D array
    }
    delete[] arr; // Delete the pointer to the 4D array

    return 0;
}
