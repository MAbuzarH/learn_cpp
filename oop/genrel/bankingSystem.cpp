#include <iostream>
using namespace std;

// Abstract Account class
class Account
{
private:
    int accountNumber;

protected:
    double balance;

public:
    Account(int accNumber, double initBalance) : accountNumber(accNumber), balance(initBalance) {}
    void deposit(double amount)
    {
        balance += amount;
    }
    virtual void withdraw(double amount) = 0; // Pure virtual function
    double getBalance()
    {
        return balance;
    }
    void accountDetails()
    {
        cout << "---Account Details---" << endl;
        cout << "accountNumber: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

// SavingsAccount class
class SavingsAccount : public Account
{
private:
    double interestRate;

public:
    SavingsAccount(int accNumber, double initBalance, double rate)
        : Account(accNumber, initBalance), interestRate(rate) {}

    void withdraw(double amount) override
    {
        if (amount <= balance)
        {
            balance -= amount;
        }
        else
        {
            cout << "Insufficient balance!" << endl;
        }
    }

    void addInterest()
    {
        balance += balance * interestRate;
    }
};

// CheckingAccount class
class CheckingAccount : public Account
{
private:
    double overdraftLimit;

public:
    CheckingAccount(int accNumber, double initBalance, double limit)
        : Account(accNumber, initBalance), overdraftLimit(limit) {}

    void withdraw(double amount) override
    {
        if (amount <= balance + overdraftLimit)
        {
            balance -= amount;
        }
        else
        {
            cout << "Overdraft limit exceeded!" << endl;
        }
    }
};

int main()
{
    SavingsAccount savings(1001, 500.0, 0.05);
    CheckingAccount checking(1002, 500.0, 100.0);

    // Test SavingsAccount
    savings.deposit(200.0);
    savings.addInterest();
    savings.withdraw(100.0);
    cout << "Savings Account Balance: " << savings.getBalance() << endl;
    savings.accountDetails();
    // Test CheckingAccount
    checking.deposit(200.0);
    checking.withdraw(700.0);
    cout << "Checking Account Balance: " << checking.getBalance() << endl;

    return 0;
}
