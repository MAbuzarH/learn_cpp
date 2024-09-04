#include <iostream>
#include <string>

using namespace std;

class Base
{
private:
    int Value;

public:
    Base() : Value{0}
    {
        cout << "no arg base constrcture called" << endl;
    }
    // default constructor
    Base(int value) : Value{value}
    {
        cout << " arg (int)  base constrcture called" << endl;
    }
    // copy constructor
    Base(const Base &other) : Value{other.Value}
    {
        cout << "Base copy constructor" << endl;
    }

    Base &operator=(const Base &rhs)
    {
        cout << "Base opreatr=" << endl;
        if (this == &rhs)
            return *this;
        this->Value = rhs.Value;
        return *this;
    }
    ~Base()
    {
        cout << "Base destructor called" << endl;
    }
};

class Drive : public Base
{

private:
    int double_Value;

public:
    Drive() : Base{}, double_Value{0}
    {
        cout << "no arg Drive constrcture called" << endl;
    }
    Drive(int v) : Base{v}, double_Value{v * 2}
    {
        cout << " arg(int) Drive constrcture called" << endl;
    }
    // drive copy constructor
    Drive(const Drive& other) :Base{other},double_Value{other.double_Value}
    {
        cout<<"drived copy constrcture \n";
    }
    Drive &operator=(const Drive &rhs){
        cout<<"drived  operator= \n";
     if(this == &rhs) return *this;
     
      Base::operator=(rhs);
       this->double_Value = rhs.double_Value;
      return *this;
    } 
    ~Drive()
    {
        cout << "Drive destructor called" << endl;
    }
};
int main()
{
    // Base b{100};
    // Base b1{b};
    // b = b1;
    Drive d{100};
    Drive d1{d};
    d=d1;
    return 0;
}