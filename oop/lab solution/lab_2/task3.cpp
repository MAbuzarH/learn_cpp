// #include <iostream>

// using namespace std;

// class circle
// {
// private:
//     int m_radius;
//     int m_originx;
//     int m_originy;

// public:
//     // constrcture:
//     circle(int radius = 0, int originx = 0, int originy = 0) : m_radius(radius), m_originx(originx), m_originy(originy) {}

//     // getter
//     int get_radius() const { return m_radius; }
//     int get_originx() const { return m_originx; }
//     int get_originy() const { return m_originy; }

//     // setter
//     void set_radius(int r) { m_radius = r; }
//     void set_originy(int originy) { m_originy = originy; }
//     void set_originx(int originx) { m_originx = originx; }

//     // business logic
//     double calc_area()
//     {
//         double a = 3.14 * this->m_radius * this->m_radius;
//         return a;
//     }

//     double calc_circumf()
//     {
//         double c = 2 * 3.14 * this->m_radius;
//         return c;
//     }

//     double calc_diamat()
//     {
//         double d = this->m_radius / 2;
//         return d;
//     }
// };

// int main()
// {
//     circle c1(4, 5, 6);
//     circle c2(6, 5, 6);
//     circle c3(8, 5, 6);
//     cout << "circle area: " << c1.calc_area() << endl;
//     cout << "circle curcumference: " << c1.calc_circumf() << endl;
//     cout << "circle curcumference: " << c1.calc_diamat() << endl;

//     return 0;
// }
#include <iostream>
#include <cmath>

using namespace std;

class Circle {
private:
    int h, k; // Center coordinates
    int r;    // Radius

public:
    // Constructor
    Circle(int centerX, int centerY, int radius)
        : h(centerX), k(centerY), r(radius) {}

    // Function to display the equation of the circle
    void displayEquation() const {
        cout << "(x - " << h << ")^2 + (y - " << k << ")^2 = " << r * r << endl;
    }

    // Function to check if a point is on the circle (for simulation purposes)
    bool isPointOnCircle(int x, int y) const {
        return pow((x - h), 2) + pow((y - k), 2) == pow(r, 2);
    }
};

int main() {
    int centerX = 3;
    int centerY = 4;
    int radii[] = {5, 10, 15}; // Different radii for concentric circles

    // Creating and displaying concentric circles
    for (int i = 0; i < 3; i++) {
        Circle c(centerX, centerY, radii[i]);
        cout << "Equation of Circle " << i + 1 << ": ";
        c.displayEquation();
    }

    // Example: Check if a point is on any of the circles
    int testX = 8, testY = 4; // Example point
    cout << "Checking if point (" << testX << ", " << testY << ") is on any of the circles:" << endl;

    for (int i = 0; i < 3; i++) {
        Circle c(centerX, centerY, radii[i]);
        if (c.isPointOnCircle(testX, testY)) {
            cout << "Point is on Circle with radius " << radii[i] << endl;
        }
    }

    return 0;
}
