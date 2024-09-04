#ifndef _ACCOUNT_UITIL_H_
#define _ACCOUNT_UITIL_H_

#include <vector>
#include <iostream>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"


using namespace std;

// utility helper functions for Account

void display(const vector<Account> &accounts);
void deposit(vector<Account> &accounts, double amount);
void withdraw(vector<Account> &accounts, double amount);

// utility helper functions for Savings_Account
void display(const vector<Savings_Account> &accounts);
void deposit(vector<Savings_Account> &accounts, double amount);
void withdraw(vector<Savings_Account> &accounts, double amount);

// utility helper functions for Savings_Account
void display(const vector<Checking_Account> &accounts);
void deposit(vector<Checking_Account> &accounts, double amount);
void withdraw(vector<Checking_Account> &accounts, double amount);

// utility helper functions for Savings_Account
void display(const vector<Trust_Account> &accounts);
void deposit(vector<Trust_Account> &accounts, double amount);
void withdraw(vector<Trust_Account> &accounts, double amount);


#endif