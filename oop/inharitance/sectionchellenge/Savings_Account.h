#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_
#include <iostream>
#include "Account.h"

using namespace std;

class Savings_Account : public Account
{
  friend ostream &operator<<(ostream &os, const Savings_Account &account);

private:
  static constexpr const char *def_name = "Unnamed saving Account";
  static constexpr double def_bal = 0.0;
  static constexpr double def_int_rate = 0.0;

protected:
  double int_Rate;

public:
  Savings_Account(string name = def_name, double balance = def_bal, double int_rate = def_int_rate);

  bool deposit(double amount);
  // withdervel is inharetes from Account
};

#endif