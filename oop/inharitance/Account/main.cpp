#include <iostream>
#include "Account.h"
#include "Account.cpp"
#include "Savings_Account.h"
#include "Saving_Account.cpp"

using namespace std;

int main()
{

    Account acc{"Ali", 1000};
    acc.deposit(2000.0);
    acc.withdraw(500);
    cout << acc;
    cout << endl;

    /*
    cout << "account ======= \n";
    Account acc;
    acc.deposit(2000.0);
    acc.withdraw(500);
    cout << endl;

    Account *p_acc{nullptr};
    p_acc = new Account();
    p_acc->deposit(1000.0);
    p_acc->withdraw(500.0);
    delete p_acc;

    cout << endl;
    cout << " saving account ======= \n";
    Saving_Account sav_acc;
    sav_acc.deposit(2000.0);
    sav_acc.withdraw(500);
    cout << endl;

    Saving_Account *p_sav_acc{nullptr};
    p_sav_acc = new Saving_Account();
    p_sav_acc->deposit(1000.0);
    p_sav_acc->withdraw(500.0);
    delete p_sav_acc;
    cout << endl;

    cout << " ======== ======= \n";
*/
    return 0;
}
