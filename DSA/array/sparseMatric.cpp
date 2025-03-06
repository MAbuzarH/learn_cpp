#include <iostream>
#include <vector>
using namespace std;
// Class to represent a sparse matrix using Coordinate List (COO) format
class SparseMatrix
{
private:
    int rows, cols;       // Number of rows and columns in the matrix
    vector<int> rowIndex; // List of row indices for non-zero elements
    vector<int> colIndex; // List of column indices for non-zero elements
    vector<int> value;    // List of non-zero values
public:
    // Constructor to initialize matrix size
    SparseMatrix(int r, int c) : rows(r), cols(c) {}
    // Function to add a non-zero element to the sparse matrix
    void addElement(int r, int c, int val)
    {
        if (val != 0)
        {
            rowIndex.push_back(r);
            colIndex.push_back(c);
            value.push_back(val);
        }
    }
    // Function to display the sparse matrix
    void display()
    {
        cout << "Row Index: ";
        for (int r : rowIndex)
            cout << r << " ";
        cout << endl;
        cout << "Column Index: ";
        for (int c : colIndex)
            cout << c << " ";
        cout << endl;
        cout << "Values: ";
        for (int v : value)
            cout << v << " ";
        cout << endl;
    }
};
int main()
{
    // Create a sparse matrix of size 4x4
    SparseMatrix sparse(4, 4);
    // Add some non-zero elements to the sparse matrix
    sparse.addElement(0, 3, 3);
    sparse.addElement(1, 1, 2);
    sparse.addElement(3, 2, 4);
    // Display the sparse matrix
    cout << "Sparse Matrix Representation (COO Format): " << endl;
    sparse.display();
    return 0;
}