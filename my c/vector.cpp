#include <iostream>
#include <vector>  // Include the vector header
using namespace std;
int main() {
    // Declare a vector of integers
    vector<int> myVector;

    // Add elements to the vector
    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);

    // Access elements by index
    cout << "Element at index 0: " << myVector[0] << std::endl;
    cout << "Element at index 1: " << myVector[1] << std::endl;

    // Get the size of the vector
    cout << "Size of vector: " << myVector.size() << std::endl;

    // Remove the last element
    myVector.pop_back();

    // Print the updated vector
    cout << "Updated vector: ";
    for (size_t i = 0; i < myVector.size(); ++i) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

