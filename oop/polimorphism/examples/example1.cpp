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

int main()
{

    cout << "====pointers ==== \n";
    Account *p1 = new Account();
    Account *p2 = new Checking();
    Account *p3 = new Saving();
    Account *p4 = new Trust();

    p1->withdraw(1000);
    p2->withdraw(1000);
    p3->withdraw(1000);
    p4->withdraw(1000);

    // Account *arr[] = {p1, p2, p3, p4}

    cout << "==cleaning === \n";
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    return 0;
}