#ifndef _SAVING_ACCOUNT_H_
#define _SAVING_ACCOUNT_H_
#include <iostream>
#include "Account.h"

using namespace std;

class Saving_Account : public Account
{
  friend ostream &operator<<(ostream &os, const Saving_Account &account);

protected:
  double int_Rate;

public:
  Saving_Account();
  Saving_Account(string name, double balance, double int_rate);

  void deposit(double amount);
  // withdervel is inharetes from Account

  ~Saving_Account();
};

#endif