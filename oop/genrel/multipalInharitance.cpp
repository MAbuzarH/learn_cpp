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
class Parent2
{
public:
    Parent2()
    {
        cout << "in parent2" << endl;
    }
};
class Child : public Parent1, public Parent2
{
public:
    Child()
    {
        cout << "in Child" << endl;
    }
};

int main()
{
    Child c1;
    return 0;
}