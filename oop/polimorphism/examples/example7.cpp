#include <iostream>

using namespace std;

class I_printable
{
    friend ostream &operator<<(ostream &os, const I_printable &obj);

public:
    virtual void print(ostream &os) const = 0;
    virtual ~I_printable() {};
};

ostream &operator<<(ostream &os, const I_printable &obj)
{
    obj.print(os);
    return os;
}

class Account : public I_printable
{

public:
    virtual void withdraw(double ammount)
    {
        cout << "Account::withdraw \n";
    }
    virtual void print(ostream &os) const override
    {
        os << "Account::display \n";
    }
    virtual ~Account() {};
};

class Checking : public Account
{

public:
    virtual void withdraw(double ammount)
    {
        cout << "Checking::withdraw \n";
    }
    virtual void print(ostream &os) const override
    {
        os << "Checking::display \n";
    }
    virtual ~Checking() {};
};

class Saving : public Account
{

public:
    virtual void withdraw(double ammount)
    {
        cout << "Saving::withdraw \n";
    }
    virtual void print(ostream &os) const override
    {
        os << "Saving::display \n";
    }
    virtual ~Saving() {};
};

class Trust : public Account
{
public:
    virtual void withdraw(double ammount)
    {
        cout << "Trust::withdraw \n";
    }
    virtual void print(ostream &os) const override
    {
        os << "Trust::display \n";
    }
    virtual ~Trust() {};
};

class Dog : public I_printable
{
public:
    virtual void print(ostream &os) const override
    {
        os << "woof woof \n";
    }
};

void print(const I_printable &obj)
{
    cout << obj << endl;
}
int main()
{

    Dog *dog = new Dog();
    print(*dog);

    Account *a = new Account();
    print(*a);

    // Account a;
    // cout << a << endl;
    // Checking c;
    // cout << c << endl;
    // Saving s;
    // cout << s << endl;
    // Trust t;
    // cout << t << endl;

    Account *p1 = new Account();
    cout << *p1 << endl;
    Account *p2 = new Checking;
    cout << *p2 << endl;

    // Account p1;
    // Account &ref = p1;
    // cout << ref << endl;
    // Checking c;
    // Account &ref2 = c;
    // cout << ref2 << endl;

    return 0;
}