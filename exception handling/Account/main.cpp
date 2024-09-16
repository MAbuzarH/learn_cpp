// Section 16
// Challenge
#include <iostream>
#include <memory>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"
#include "I_prantable.h"
#include "IllegalBalanceException.h"
#include "InsuficentFundsExecption.h"

using namespace std;

int main()
{
    cout.precision(2);
    cout << fixed;

    // cout << A << endl;
    try
    {
        Checking_Account A("test", -200);
        // A.deposit(-200);
        A.withdraw(20000);
    }
    catch (const IllegalBalanceException &ex)
    {
        cout << "error caughht \n";
    }
    catch (const InsuficentFundsExecption &ex)
    {
        cout << "error caughht in insofi\n";
    }
    cout << " bye\n";

    return 0;
}
