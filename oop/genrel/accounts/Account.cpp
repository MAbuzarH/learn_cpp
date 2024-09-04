#include "Account.h"

bool Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        return true;
    }
    return false;
}

bool Account::withdraw(double amount) {
    if (amount > balance || amount <= 0) {
        return false;
    } else {
        balance -= amount;
        return true;
    }
}

