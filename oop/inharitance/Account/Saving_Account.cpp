#include <iostream>
#include "Savings_Account.h"
using namespace std;

// parametrise constrcture
Saving_Account::Saving_Account(string name, double balance, double int_rate)
    : Account(name, balance), int_Rate(int_rate)
{
}

// no arg constructor
Saving_Account::Saving_Account() : Saving_Account{" ", 0.0, 0.0}
{
}

// deposit method
void Saving_Account::deposit(double amount)
{
    amount = amount + (amount * int_Rate / 100);
    Account::deposit(amount);
}

ostream &operator<<(ostream &os, const Saving_Account &account)
{
    os << "saving account balance is: " << account.Balance << " intrest rate: " << account.int_Rate;
    return os;
}

// distrcture
Saving_Account::~Saving_Account()
{
}