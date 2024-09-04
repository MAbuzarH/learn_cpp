#include <iostream>
#include <string>
#include "Account.h"
using namespace std;

// constructor
Account::Account(string name, double balance) : Name(name), Balance(balance)
{
}

// deposit
bool Account::deposit(double amount)
{
    if (amount < 0)
    {
        return false;
    }
    Balance += amount;
    return true;
}

// withdraw
bool Account::withdraw(double amount)
{
    if (amount > Balance)
    {
        return false;
    }
    Balance -= amount;
    return true;
}

// get current balance
double Account::get_balance() const
{
    return Balance;
}

ostream &operator<<(ostream &os, const Account &account)
{
    os << "[Account Name: " << account.Name << " Balance: " << account.Balance << "]";
    return os;
}