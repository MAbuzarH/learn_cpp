#include <iostream>
#include <vector>
using namespace std;
class Shape
{
public:
    virtual void draw() = 0;
    virtual void rotate() = 0;
    virtual ~Shape() {};
};

class Open_Shape : public Shape
{
public:
    virtual ~Open_Shape() {};
};

class Close_Shape : public Shape
{
public:
    virtual ~Close_Shape() {};
};

class Line : public Open_Shape
{
public:
    virtual void draw() override
    {
        cout << "drawing a line:" << endl;
    }
    virtual void rotate() override
    {
        cout << "rotate a line:" << endl;
    }

    virtual ~Line() {};
};

class Circle : public Close_Shape
{
public:
    virtual void draw() override
    {
        cout << "drawing a Circle:" << endl;
    }
    virtual void rotate() override
    {
        cout << "rotate a Circle:" << endl;
    }

    virtual ~Circle() {};
};

class Square : public Close_Shape
{
public:
    virtual void draw() override
    {
        cout << "drawing a Square:" << endl;
    }
    virtual void rotate() override
    {
        cout << "rotate a Square:" << endl;
    }

    virtual ~Square() {};
};

void screen(vector<Shape *> &shapes)
{
    cout << "refreching  \n";
    for (const auto s : shapes)
        s->draw();
}
int main()
{
    /*
    error
    Shape s;
    Shape *s = new Shape();
    because we cannot intenseate an abstract class

    */
    // Circle c;
    // c.draw(); // Drawing a circle

    // Shape *c = new Circle();
    // c->draw();   // Drawing a circle
    // c->rotate(); //
    Shape *c1 = new Circle();
    Shape *c2 = new Line();
    Shape *c3 = new Square();

    vector<Shape *> shapes = {c1, c2, c3};

    // for (const auto s : shapes)
    //     s->draw();
    screen(shapes);
    delete c1;
    delete c2;
    delete c3;
    return 0;
}