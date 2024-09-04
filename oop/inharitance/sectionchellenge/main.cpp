#include <iostream>
#include "Account.h"
#include "Savings_Account.h"
#include "Account_Uitil.h"
#include "Checking_Account.h"
#include "Trust_Account.h"

using namespace std;

int main()
{
    cout.precision(2);
    cout << fixed;

    Trust_Account acc{"Ali", 1000};
    acc.deposit(5000);
    cout << acc << endl;
    // acc.withdraw(acc, 5000); // error
    // acc.withdraw(acc, 100);
    // acc.withdraw(acc, 100);
    // acc.withdraw(acc, 100);
    // acc.withdraw(acc, 100);
    cout << acc << endl;
    // cout << acc << endl;

    // vector<Checking_Account> Che_acc;
    // Che_acc.push_back(Checking_Account{"Larry"});
    // Che_acc.push_back(Checking_Account{"Currly", 2000});
    // Che_acc.push_back(Checking_Account{"stoogy", 5000});
    // display(Che_acc);
    // deposit(Che_acc, 1000);
    // withdraw(Che_acc, 500);
    /*
        // accounts

        vector<Account> accounts;
        accounts.push_back(Account{"Larry"});
        accounts.push_back(Account{"Currly", 2000});
        accounts.push_back(Account{"stoogy", 5000});

        display(accounts);
        deposit(accounts, 1000);
        withdraw(accounts, 2000);

        vector<Savings_Account> sav_accounts;
        sav_accounts.push_back(Savings_Account{"super Larry"});
        sav_accounts.push_back(Savings_Account{"bat Currly", 2000});
        sav_accounts.push_back(Savings_Account{"col stoogy", 5000});

        display(sav_accounts);
        deposit(sav_accounts, 1000);
        withdraw(sav_accounts, 2000);
        // savings;
    */
    return 0;
}