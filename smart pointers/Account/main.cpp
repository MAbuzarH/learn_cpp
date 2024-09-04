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

using namespace std;

class Test
{
private:
    int data;

public:
    Test() : data{0}
    {
        cout << "Test Constructor" << endl;
    }
    Test(int d) : data{d}
    {
        cout << "Test Constructor ( " << data << " ) " << endl;
    }
    int get_data() const { return data; }
    ~Test() { cout << "Test Destructor ( " << data << " ) " << endl; }
};

int main()
{
    cout.precision(2);
    cout << fixed;
    // // Test *t1 = new Test(1000);
    // // delete t1;
    // unique_ptr<Test> t1{new Test(1000)};
    // unique_ptr<Test> t2 = make_unique<Test>(100);
    // unique_ptr<Test> t3;
    // //  t3 = t2;not allowed
    // t3 = move(t2);

    // unique_ptr<Account> a1 = make_unique<Checking_Account>("Moe", 1000);
    // cout << *a1 << endl;
    // a1->deposit(5000);
    // cout << *a1 << endl;
    // vector<unique_ptr<Account>> accounts;
    // accounts.push_back(make_unique<Savings_Account>("Ali", 300));
    // accounts.push_back(make_unique<Trust_Account>("qasim", 3000, 6));
    // accounts.push_back(make_unique<Checking_Account>("jasm", 300, 9));
    // //  for(auto account : accounts){ // we cant do this
    // for (const auto &account : accounts)
    // {
    //     cout << *account << endl;
    // }

    //////// shared pointer

    // shared_ptr<int> p1{new int(100)};
    // cout << *p1 << endl;
    // cout << p1.use_count() << endl;
    // shared_ptr<int> p2{p1};
    // cout << p1.use_count() << endl;
    // cout << *p2 << endl;
    // p1.reset();
    // cout << p1.use_count() << endl;
    // cout << *p1 << endl;

    //     shared_ptr<Test> t1{new Test(1000)};
    //     shared_ptr<Test> t2 = make_shared<Test>(100);
    //     shared_ptr<Test> t3;
    //     t3 = t2;
    //     t3 = move(t2);
    //   //  cout << t3->get_data() << endl;

    shared_ptr<Account> acc1 = make_shared<Checking_Account>("Moe", 2000);
    shared_ptr<Account> acc2 = make_shared<Savings_Account>("Nini", 1000, 9);
    shared_ptr<Account> acc3 = make_shared<Trust_Account>("Moe", 2000, 3);
    vector<shared_ptr<Account>> accounts;
    accounts.push_back(acc1);
    accounts.push_back(acc2);
    accounts.push_back(acc3);
    for (auto &acc : accounts)
    {
        cout << *acc << endl;
        cout << "use count:" << acc.use_count() << endl;
    }
    return 0;
}
