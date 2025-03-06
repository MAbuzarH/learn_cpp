#include <bits/stdc++.h>

using namespace std;

class sparceMatrix
{
private:
    int rows, cols;
    vector<int> rowIndex;
    vector<int> colIndex;
    vector<int> value;

public:
    sparceMatrix(int r, int c) : rows(r), cols(c)
    {
    }
    void addElement(int r, int c, int val)
    {
        if (val != 0)
        {
            rowIndex.push_back(r);
            colIndex.push_back(c);
            value.push_back(val);
        }
    }
    // function to display
    void display()
    {
        cout << "rows [";
        for (int r : rowIndex)
        {
            cout << r << ", ";
        }
        cout << "]";
        cout << endl;
        cout << "cols [";
        for (int c : colIndex)
        {
            cout << c << ",";
        }
        cout << "]";
        cout << endl;
        cout << "value [";
        for (int v : value)
        {
            cout << v << ", ";
        }
        cout << "]";
    }
};

int main()
{
    // Create a sparse matrix of size 4x4
    sparceMatrix sparse(4, 4);
    // Add some non-zero elements to the sparse matrix
    sparse.addElement(0, 3, 3);
    sparse.addElement(1, 1, 2);
    sparse.addElement(3, 2, 4);
    // Display the sparse matrix
    cout << "Sparse Matrix Representation (COO Format): " << endl;
    sparse.display();
    return 0;
}