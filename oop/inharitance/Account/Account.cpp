#include <iostream>
#include "Account.h"
using namespace std;

// no arg constructor
Account::Account() : Name("Account name"), Balance(0)
{
}

// parametrized constructor
Account::Account(string name, double balance) : Name{name}, Balance{balance}
{
}

// deposit
void Account::deposit(double amount)
{
    this->Balance += amount;
}

// withdraw
void Account::withdraw(double amount)
{
    if (Balance >= amount)
        this->Balance -= amount;
    else
        cout << "insuficent fund" << endl;
}

ostream &operator<<(ostream &os, const Account &account)
{
    os << " \n Account Holder: " << account.Name;
    os << " \n Account Balance: " << account.Balance;
    return os;
}

Account::~Account()
{
}