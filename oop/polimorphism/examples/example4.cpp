#include <iostream>

using namespace std;

class Account
{

public:
    virtual void withdraw(double amount)
    {
        cout << " I am in the account withdraw" << endl;
    }
    virtual ~Account()
    {
        cout << "account:: distrcture \n";
    }
};
class Checking : public Account
{

public:
    virtual void withdraw(double amount)
    {
        cout << " I am in the Checking withdraw" << endl;
    }
    virtual ~Checking()
    {
        cout << "Checking:: distrcture \n";
    }
};
class Saving : public Account
{

public:
    virtual void withdraw(double amount)
    {
        cout << " I am in the Saving withdraw" << endl;
    }
    virtual ~Saving()
    {
        cout << "Saving:: distrcture \n";
    }
};
class Trust : public Account
{

public:
    virtual void withdraw(double amount)
    {
        cout << " I am in the Trust withdraw" << endl;
    }
    virtual ~Trust()
    {
        cout << "Trust:: distrcture \n";
    }
};

void do_withdraw(Account &accout, double amount)
{
    accout.withdraw(amount);
}
int main()
{
    // refrence of base class
    // Account a;
    // Account &ref = a;
    // a.withdraw(100);

    // Trust t;
    // Account &ref1 = t;
    // ref1.withdraw(100);

    Account a1;
    Trust a2;
    Saving a3;
    Checking a4;

    do_withdraw(a1, 100);
    do_withdraw(a2, 100);
    do_withdraw(a3, 100);
    do_withdraw(a4, 100);
    return 0;
}