#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_
#include <vector>
#include "Account.h"

// Utility helper functions for Account class

// void display(const Account &accounts);
//  void deposit(const Checking_Account &acc, double amount);
void display(const std::vector<Account *> &accounts);
void deposit(std::vector<Account *> &accounts, double amount);
void withdraw(std::vector<Account *> &accounts, double amount);

#endif