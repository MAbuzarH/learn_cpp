#include <iostream>
#include <memory>

using namespace std;

class B;
class A
{
    shared_ptr<B> b_ptr;
public:
    void set_b(shared_ptr<B> &b)
    {
        b_ptr = b;
    }
    A() { cout << "A::A" << endl; }
    ~A() { cout << "A::~" << endl; }
};

class B
{
    // shared_ptr<A> a_ptr;
    weak_ptr<A> a_ptr;

public:
    void set_a(shared_ptr<A> &a)
    {
        a_ptr = a;
    }
    B() { cout << "B::B" << endl; }
    ~B() { cout << "B::~" << endl; }
};

int main()
{
    shared_ptr<A> a = make_shared<A>();
    shared_ptr<B> b = make_shared<B>();
    a->set_b(b);
    b->set_a(a); // this will leak memory

    return 0;
}