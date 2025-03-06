#include <iostream>
using namespace std;
// A simple polynomial class using an array representation
class Polynomial
{
private:
    int *coefficients;
    int max_degree;

public:
    // Constructor
    Polynomial(int degree)
    {
        max_degree = degree;
        coefficients = new int[max_degree + 1]{0}; // Initialize all coefficients to 0
    }
    // Function to set the coefficient for a given degree
    void setCoefficient(int degree, int coefficient)
    {
        coefficients[degree] = coefficient;
    }
    // Display the polynomial
    void display()
    {
        for (int i = max_degree; i >= 0; i--)
        {
            if (coefficients[i] != 0)
            {
                cout << coefficients[i] << "x^" << i;
                if (i != 0)
                    cout << " + ";
            }
        }
        cout << endl;
    }
    ~Polynomial()
    {
        delete[] coefficients;
    }
};
int main()
{
    Polynomial poly(4);         // Create a polynomial of degree 4
    poly.setCoefficient(4, 3);  // Set coefficient of x^4 as 3
    poly.setCoefficient(3, 5);  // Set coefficient of x^3 as 5
    poly.setCoefficient(1, -6); // Set coefficient of x as -6
    poly.setCoefficient(0, 2);  // Set constant term as 2
    cout << "Polynomial: ";
    poly.display(); // Output: 3x^4 + 5x^3 - 6x^1 + 2x^0
    return 0;
}
