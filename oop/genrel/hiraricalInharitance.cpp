#include <iostream>
using namespace std;
class Parent1
{
public:
    Parent1()
    {
        cout << "in parent1" << endl;
    }
};

class Child1 : public Parent1
{
public:
    Child1()
    {
        cout << "in Child" << endl;
    }
};
class Child2 : public Parent1
{
public:
    Child2()
    {
        cout << "in Child2" << endl;
    }
};

int main()
{
    Child1 c1;
     Child2 c2;
    return 0;
}