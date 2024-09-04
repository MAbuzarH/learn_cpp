#include <iostream>
using namespace std;

class Rectangle
{
public:
    int l;
    int w;
    Rectangle()
    { // this is default constructor no arguments passed
        l = 0;
        w = 0;
    }
    Rectangle(int x, int y)
    { // this is parametrized constructor  arguments are passed
        l = x;
        w = y;
    }
    Rectangle(Rectangle &r)
    { // this is copy constructor initilaize an obj by other obj
        l = r.l;
        w = r.w;
    }
};

int main()
{
    Rectangle r1;
    cout << r1.l << " " << r1.w << endl;
    Rectangle r2(5, 8);
    cout << r2.l << " " << r2.w << endl;
    Rectangle r3 = r2;
    cout << r3.l << " " << r3.w << endl;
    return 0;
}