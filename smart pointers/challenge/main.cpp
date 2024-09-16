// custom deleters for smart pointers

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Test
{
    friend ostream &operator<<(ostream &os, const Test &test);

private:
    int data;

public:
    Test() : data(0) { cout << "Test data constrcture(" << data << ") \n"; }

    Test(int data) : data(data) { cout << "Test data constrcture(" << data << ") \n"; }
    int get_data() const { return data; }
    ~Test() { cout << "Test data distrcture(" << data << ") \n"; }
};

ostream &operator<<(ostream &os, const Test &test)
{
    os << test.data;
    return os;
}
// we can also use this unique_ptr<vector<shared_ptr<Test>>>
auto make()
{
    unique_ptr<vector<shared_ptr<Test>>> vac{make_unique<vector<shared_ptr<Test>>>()};
    return vac;
    //{make_unique<vector<shared_ptr<Test>>>()};
}
void fill(vector<shared_ptr<Test>> &vac, int num)
{
    int data;
    for (int i = 0; i < num; i++)
    {
        cout << "enter data for [" << i + 1 << "]" << endl;
        cin >> data;
        // shared_ptr<Test> ptr = make_shared<Test>(data); // added this after watching solution // we can  use single line
        vac.push_back(make_shared<Test>(data));
    }
}
void display(const vector<shared_ptr<Test>> &vec)
{
    for (const auto &v : vec)
    {
        cout << "\t " << *v << endl;
    }
}
int main()
{
    unique_ptr<vector<shared_ptr<Test>>> vact;
    vact = make();

    cout << "how many data points you want to enter \n";
    int num;
    cin >> num;
    fill(*vact, num);
    cout << "======================\n";
    display(*vact);
    cout << "======================\n";
    return 0;
}

// tryies
//  shared_ptr<Test> a{make_shared<Test>(10)};
//  shared_ptr<Test> b{make_shared<Test>(20)};
//  shared_ptr<Test> c{make_shared<Test>(30)};
//  vact->push_back(a);
//  vact->push_back(b);
//  vact->push_back(c);
//  cout << &vact;

// cout << vact. << endl;