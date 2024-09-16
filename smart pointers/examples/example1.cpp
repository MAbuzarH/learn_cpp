// custom deleters for smart pointers

#include <iostream>
#include <memory>

using namespace std;

class Test
{
private:
    int data;

public:
    Test() : data(0) { cout << "Test data constrcture(" << data << ") \n"; }

    Test(int data) : data(data) { cout << "Test data constrcture(" << data << ") \n"; }
    int get_data() const { return data; }
    ~Test() { cout << "Test data distrcture(" << data << ") \n"; }
};

void my_deleter(Test *ptr)
{
    cout << "Using custom function deleter " << endl;
    delete ptr;
}
int main()
{
    // using custm function
    {
        shared_ptr<Test> t1{new Test(100), my_deleter};
    }
    {
        shared_ptr<Test> t2{new Test(10), [](Test *ptr)
                            {
                                cout << "Using [] function deleter " << endl;
                                delete ptr;
                            }};
    }

    return 0;
}