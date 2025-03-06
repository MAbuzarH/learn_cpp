#include <iostream>

using namespace std;

class P
{
private:
    int x;
    int y;

public:
    P(int a, int b) : x(a), y(b)
    {
    }
    void display()
    {
        cout << "x: " << x << " y: " << y << endl;
    }
};

int main()
{
    // P p1(2, 3);
    // p1.display();
    P p2[3] = {P(1, 2), P(2, 4),P(3,9)};
    for (int i = 0; i < 3; i++)
    {
        p2[i].display();
    }
}