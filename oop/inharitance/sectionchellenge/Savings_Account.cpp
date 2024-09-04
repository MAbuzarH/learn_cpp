#include <iostream>
#include "Savings_Account.h"
using namespace std;

// parametrise constrcture
Savings_Account::Savings_Account(string name, double balance, double int_rate)
    : Account(name, balance), int_Rate(int_rate)
{
}

// deposit method
bool Savings_Account::deposit(double amount)
{
    amount = amount + (amount * int_Rate / 100);
    return Account::deposit(amount);
}

ostream &operator<<(ostream &os, const Savings_Account &account)
{
    os << "[Saving account Name is: " << account.Name << " Balance: " << account.Balance << " intrest rate: " << account.int_Rate << "]";
    return os;
}
