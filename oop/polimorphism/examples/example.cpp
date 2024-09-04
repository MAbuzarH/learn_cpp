#include <iostream>
#include <memory>

using namespace std;

class Base
{
public:
    void say_hello() const
    {
        cout << "Hello world- i am in base object" << endl;
    }
};

class Drived : public Base
{
public:
    void say_hello() const
    {
        cout << "Hello world- i am in Drive object" << endl;
    }
};

void greetings(const Base &obj)
{

    cout << "Greetings --:";
    obj.say_hello();
}

int main()
{
    Base b;
    b.say_hello();

    Drived d;
    d.say_hello();

    greetings(b);
    greetings(d);

    Base *ptr = new Drived();
    ptr->say_hello();

    unique_ptr<Base> ptr1 = make_unique<Drived>();
    ptr1->say_hello();

    delete ptr;
    return 0;
}