#ifndef _CHECKING_ACCOUNT_H
#define _CHECKING_ACCOUNT_H
#include"Account.h"
#include <iostream>

using namespace std;

class Checking_Account : public Account{

friend ostream& operator<<(ostream &os,const Checking_Account &account);

private:
    static constexpr const char *def_name = "Unnamed  Account";
    static constexpr double def_bal = 0.0;
    static constexpr double per_check_fee = 1.5;
public:
Checking_Account(string name = def_name, int balance = def_bal);
bool withdraw (double amount);
// deposit is inheareted from  the Account Class whic is parent
};





#endif