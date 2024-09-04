#include <iostream>
#include "Trust_Account.h"

using namespace std;
Trust_Account::Trust_Account(string name, double balance, double int_rate) : Savings_Account(name, balance, int_rate), num_withdrawals{0}
{
}

bool Trust_Account::deposit(double amount)
{
    /*
     my solution
    if (amount >= 5000)
    {
        amount += 50;
    }
    return Savings_Account::deposit(amount);
    */
    if (amount >= bonus_threshold)
        amount += bonus_threshold;
    return Savings_Account::deposit(amount);
}

ostream &operator<<(ostream &os, const Trust_Account &account)
{
    os << "[ Trust Account" << account.Name << ": " << account.Balance << " : " << account.int_Rate << ":" << "Withdrawals:" << account.num_withdrawals << "]";
}

bool Trust_Account::withdraw(double amount)
{
    if (num_withdrawals >= MAX_WITHDRAW || (amount > Balance * max_withdraw_percent))
    {
        return false;
    }
    else
    {
        ++num_withdrawals;
        return Savings_Account::withdraw(amount);
    }
}

// bool Trust_Account::withdraw(Trust_Account account, double amount)
// {
//     MAX_WITHDRAW += 1;
//     if (MAX_WITHDRAW <= 3)
//     {

//         if (amount <= (account.Balance * 0.2))
//         {
//             return Savings_Account::withdraw(amount);
//         }
//     }
//     else
//         return false;
// }

bool Trust_Account::withdraw(double amount)
{
}