#include <iostream>
using namespace std;

class Polynomial
{
private:
    int max_degree;
    int *coefficient;

public:
    // constructor
    Polynomial(int degree)
    {
        max_degree = degree;
        coefficient = new int[max_degree + 1]{0};
    }

    void set_cofficient(int coeffi, int degree)
    {
        coefficient[degree] = coeffi;
    }

    void display()
    {
        for (int i = max_degree; i >= 0; i--)
        {
            if (coefficient[i] != 0)
            {
                cout << coefficient[i] << "x^" << i;
                if (i != 0)
                cout << " + ";
            }
        }
        cout << endl;
    }

    ~Polynomial()
    {
        delete[] coefficient;
    }
};

int main()
{
    Polynomial poly(4);
    poly.set_cofficient(3, 4);
    poly.set_cofficient(2, 3);
    poly.set_cofficient(-6, 1);
    poly.set_cofficient(7, 0);
    poly.display();
    return 0;
}