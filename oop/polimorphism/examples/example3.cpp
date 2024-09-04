#include <iostream>
using namespace std;

class Base
{
public:
    virtual void say_hello() const
    {
        cout << "Base::say_hello \n";
    }
    virtual ~Base()
    {
        cout << "Base::~base \n";
    }
};

class Drive : public Base
{
public:
    void say_hello() const override
    { // first try with out const
        cout << "drive::say_hello \n";
    }
    virtual ~Drive()
    {
        cout << "Drive::~Drive \n";
    }
};

int main()
{
    Base *p1 = new Base();
    Base *p2 = new Drive();
    p1->say_hello();
    p2->say_hello();

    delete p1;
    delete p2;
    return 0;
}