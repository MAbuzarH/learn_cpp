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
    Base(int value) : Value{value}
    {
        cout << " arg (int)  base constrcture called" << endl;
    }
    ~Base()
    {
        cout << "Base destructor called" << endl;
    }
};

class Drive : public Base
{
    // using Base::Base; //not recomended to use
    /*
    because this deal with base only and remain
    drived remain on previous condition
    */
private:
    int Double_value;

public:
    Drive() : Double_value{0}
    {
        cout << "no arg Drive constrcture called" << endl;
    }
    Drive(int v) : Double_value{v * 2}
    {
        cout << " arg(int) Drive constrcture called" << endl;
    }
    ~Drive()
    {
        cout << "Drive destructor called" << endl;
    }
};
int main()
{
    // Base b; // base no arg constructor called
    //  Base b{100} // base int arg constructor called
    // Drive d; // base no arg and drive no arg constructor called
    Drive d{1000}; // base no arg and drive int arg constructor called

    /*
     cout << "base class member acces from base object" << endl;
     Base b;
     //    b.a = 100;  //ok
     //    b.b=200;  //compiler error
     //    b.c = 100; // compiler error
     cout << "base class member acces from drive object" << endl;
     Drive d;
     // d.a=100;
     // d.b = 200; //error
     // d.c= 300 /error
     */
    return 0;
}