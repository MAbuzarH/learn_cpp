#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <iostream>
#include <string>

using namespace std;
class Account
{
    friend ostream &operator<<(ostream &os, const Account &account);

protected:
    string Name;
    double Balance;

public:
    Account();
    Account(string name, double balance);
    void deposit(double amount);
    void withdraw(double amount);

    ~Account();
};

#endif