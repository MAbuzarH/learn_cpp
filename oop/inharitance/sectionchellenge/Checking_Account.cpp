#include <iostream>
#include "Checking_Account.h"

using namespace std;

Checking_Account::Checking_Account(string name, int balance) : Account(name, balance)
{
}

bool Checking_Account::withdraw(double amount)
{
    amount += per_check_fee;
    return Account::withdraw(amount);
}

ostream &operator<<(ostream &os, const Checking_Account &account)
{
    os << "[ Checking_Account " << account.Name << ":" << account.Balance << "]";
    return os;
}