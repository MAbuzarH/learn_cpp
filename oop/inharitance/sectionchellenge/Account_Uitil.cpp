#include <iostream>
// #include <vector>
#include "Account_Uitil.h"
#include "Account.h"
#include "Savings_Account.h"

using namespace std;

//  ---- Account --------------------------------
void display(const vector<Account> &accounts)
{
    cout << "=== Accounts ================== \n";
    for (const auto &account : accounts)
    {
        cout << account << endl;
    }
}

void deposit(vector<Account> &accounts, double amount)
{
    cout << "=== Depositing to Accounts ================== \n";
    for (auto &account : accounts)
    {
        if (account.deposit(amount))
        {
            cout << "Depositing amount: " << amount << " to account " << account << endl;
        }
        else
        {
            cout << "Failed depositing amount: " << amount << " to account " << account << endl;
        }
    }
}

void withdraw(vector<Account> &accounts, double amount)
{
    cout << "=== withdraiting to Accounts ================== \n";
    for (auto &account : accounts)
    {
        if (account.withdraw(amount))
        {
            cout << "withdraiting amount: " << amount << " to account " << account << endl;
        }
        else
        {
            cout << "Failed withdraw amount: " << amount << " to account " << account << endl;
        }
    }
}

// saving account --------
void display(const vector<Savings_Account> &accounts)
{
    cout << "=== Savings Accounts ================== \n";
    for (const auto &account : accounts)
    {
        cout << account;
    }
}

void deposit(vector<Savings_Account> &accounts, double amount)
{
    cout << "=== Depositing to savings Accounts ================== \n";
    for (auto &account : accounts)
    {
        if (account.deposit(amount))
        {
            cout << "Depositing amount: " << amount << " to account " << account << endl;
        }
        else
        {
            cout << "Failed depositing amount: " << amount << " to account " << account << endl;
        }
    }
}

void withdraw(vector<Savings_Account> &accounts, double amount)
{
    cout << "=== withdraiting to Savings Accounts ================== \n";
    for (auto &account : accounts)
    {
        if (account.withdraw(amount))
        {
            cout << "withdraiting amount: " << amount << " to account " << account << endl;
        }
        else
        {
            cout << "Failed withdraw amount: " << amount << " to account " << account << endl;
        }
    }
}

// checking account --------
void display(const vector<Checking_Account> &accounts)
{
    cout << "=== checking Accounts ================== \n";
    for (const auto &account : accounts)
    {
        cout << account << endl;
    }
}

void deposit(vector<Checking_Account> &accounts, double amount)
{
    cout << "=== Depositing to checking Accounts ================== \n";
    for (auto &account : accounts)
    {
        if (account.deposit(amount))
        {
            cout << "Depositing amount: " << amount << " to account " << account << endl;
        }
        else
        {
            cout << "Failed depositing amount: " << amount << " to account " << account << endl;
        }
    }
}

void withdraw(vector<Checking_Account> &accounts, double amount)
{
    cout << "=== withdraiting to Checking Accounts ================== \n";
    for (auto &account : accounts)
    {
        if (account.withdraw(amount))
        {
            cout << "withdraiting amount: " << amount << " to account " << account << endl;
        }
        else
        {
            cout << "Failed withdraw amount: " << amount << " to account " << account << endl;
        }
    }
}

// Trusted account --------
void display(const vector<Trust_Account> &accounts)
{
    cout << "=== Trusted Accounts ================== \n";
    for (const auto &account : accounts)
    {
        cout << account << endl;
    }
}

void deposit(vector<Trust_Account> &accounts, double amount)
{
    cout << "=== Depositing to trust Accounts ================== \n";
    for (auto &account : accounts)
    {
        if (account.deposit(amount))
        {
            cout << "Depositing amount: " << amount << " to account " << account << endl;
        }
        else
        {
            cout << "Failed depositing amount: " << amount << " to account " << account << endl;
        }
    }
}

void withdraw(vector<Trust_Account> &accounts, double amount)
{
    cout << "=== withdraiting to Trust Accounts ================== \n";
    for (auto &account : accounts)
    {
        if (account.withdraw(amount))
        {
            cout << "withdraiting amount: " << amount << " to account " << account << endl;
        }
        else
        {
            cout << "Failed withdraw amount: " << amount << " to account " << account << endl;
        }
    }
}
