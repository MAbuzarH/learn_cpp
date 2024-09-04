#include<iostream>
#include "Account.h"
#include"Account.cpp"
using namespace std;

int main() {
    Account a1;
    a1.set_name("Ali");
    a1.set_bal(200000.0);
    cout << "Name: " << a1.get_name() << endl;
    cout << "Balance: " << a1.get_bal() << endl;
    cout << "--------\n";

    if (a1.deposit(300.0)) {
        cout << "Balance after deposit: " << a1.get_bal() << endl;
    } else {
        cout << "Error during deposit\n";
    }

    if (a1.withdraw(250.0)) {
        cout << "Balance after withdrawal: " << a1.get_bal() << endl;
    } else {
        cout << "Low balance\n";
    }

    return 0;
}

