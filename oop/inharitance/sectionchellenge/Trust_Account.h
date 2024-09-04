#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_
#include <iostream>
#include "Savings_Account.h"
using namespace std;

class Trust_Account : public Savings_Account
{
    static constexpr int MAX_WITHDRAW = 3;
    static constexpr const char *def_name = "Unnamed Trust Account";
    static constexpr double def_bal = 0.0;
    static constexpr double def_int_rate = 0.0;
    static constexpr double bonus_amount = 50.0;
    static constexpr double bonus_threshold = 5000.0;
    static constexpr double max_withdraw_percent = 0.2;
    friend ostream &operator<<(ostream &os, const Trust_Account &account);

protected:
    int num_withdrawals;  

public:
    Trust_Account(string name = def_name, double balance = def_bal, double int_rate = def_int_rate);
    // bool deposit(double amount);
    // bool withdraw(Trust_Account account, double amount);
  bool deposit(double amount);
  bool withdraw(double amount);
};

#endif