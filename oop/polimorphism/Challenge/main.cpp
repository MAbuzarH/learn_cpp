// Section 16
// Challenge
#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"
#include "I_prantable.h"

using namespace std;

int main()
{
    cout.precision(2);
    cout << fixed;

    // Account *ptr = new Trust_Account("ali", 2000, 20);
    // display(*ptr);

    // Checking_Account account("Ali", 400);
    // account.deposit(1000);
    // // account.withdraw(1000);
    // account.print(cout);

    // Savings_Account account("Ali", 4000, 5);
    // account.print(cout);
    // account.deposit(1000);
    // account.withdraw(100);
    // account.print(cout);

    // Trust_Account account("Ali", 4000, 5);
    // account.print(cout);
    // account.deposit(1000);
    // account.withdraw(100);
    // display(account);
    // account.print(cout);

    // Accounts

    Account *p1 = new Savings_Account{"Curly", 5000, 10};
    Account *p2 = new Trust_Account{"jim", 5000};
    Account *p3 = new Savings_Account{"Curlymi", 5000};
    Account *p4 = new Checking_Account{"miCurly", 5000};
    // accounts.push_back(p1);
    // accounts.push_back(p2);
    // accounts.push_back(p3);
    // accounts.push_back(p4);
    vector<Account *> accounts = {p1, p2, p3, p4};
    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);

    cout << "displayed again" << endl;
    display(accounts);

    
    // for (int i = 0; i < accounts.size(); i++)
    // {
    //     accounts.at(i).print(cout) ;
    // }
   


    return 0;
}
