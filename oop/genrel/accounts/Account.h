#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <string>
using namespace std;

class Account {
private:
    string name;
    double balance;  // Changed to double

public:
    // Constructor
    Account() : balance(0.0) {}

    // Setters and Getters
    void set_bal(double bal) {
        balance = bal;
    }
    double get_bal() const {
        return balance;
    }
    void set_name(string n) {
        name = n;
    }
    string get_name() const {
        return name;
    }

    // Methods
    bool deposit(double amount);
    bool withdraw(double amount);
};

#endif

