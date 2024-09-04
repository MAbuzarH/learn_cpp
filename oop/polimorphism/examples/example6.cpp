#include <iostream>

using namespace std;

class Account
{
    friend ostream &operator<<(ostream &os, const Account &acc);

public:
    virtual void withdraw(double ammount)
    {
        cout << "Account::withdraw \n";
    }

    virtual ~Account() {};
};
ostream &operator<<(ostream &os, const Account &acc)
{
    os << "Account display \n";
    return os;
}

class Checking : public Account
{
    friend ostream &operator<<(ostream &os, const Checking &acc);

public:
    virtual void withdraw(double ammount)
    {
        cout << "Checking::withdraw \n";
    }

    virtual ~Checking() {};
};
ostream &operator<<(ostream &os, const Checking &acc)
{
    os << "Checking display \n";
    return os;
}

class Saving : public Account
{
    friend ostream &operator<<(ostream &os, const Saving &acc);

public:
    virtual void withdraw(double ammount)
    {
        cout << "Saving::withdraw \n";
    }

    virtual ~Saving() {};
};
ostream &operator<<(ostream &os, const Saving &acc)
{
    os << "Saving display \n";
    return os;
}

class Trust : public Account
{
    friend ostream &operator<<(ostream &os, const Trust &acc);

public:
    virtual void withdraw(double ammount)
    {
        cout << "Trust::withdraw \n";
    }

    virtual ~Trust() {};
};
ostream &operator<<(ostream &os, const Trust &acc)
{
    os << "Trust display \n";
    return os;
}

int main()
{
    // Account a;
    // cout << a << endl;
    // Checking c;
    // cout << c << endl;
    // Saving s;
    // cout << s << endl;
    // Trust t;
    // cout << t << endl;

    // Account *p1 = new Account();
    // cout << *p1 << endl;
    // Account *p2 = new Checking;
    // cout << *p2 << endl;

    // Account p1;
    // Account &ref = p1;
    // cout << ref << endl;
    // Checking c;
    // Account &ref2 = c;
    // cout << ref2 << endl;

    return 0;
}