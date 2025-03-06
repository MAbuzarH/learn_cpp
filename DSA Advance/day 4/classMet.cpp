#include <iostream>
#include <stdio.h>
using namespace std;
class Rectangle
{
private:
    int length;
    int breadth;

public:
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }
    int getLength()
    {
        return length;
    }
    int getBreadth()
    {
        return breadth;
    }
    void setBreadth(int b)
    {
        breadth = b;
    }
    void setLength(int l)
    {
        length = l;
    }
    int area()
    {
        return (length * breadth);
    }
    int param()
    {
        return 2 * (length + breadth);
    }
    ~Rectangle(){}
};
int main()
{
    Rectangle r{20, 30};
    cout << r.area();
    return 0;
}