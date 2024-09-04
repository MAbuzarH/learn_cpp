#include <iostream>

using namespace std;

class ABC
{
    int a;

public:
    void set(int b)
    {
        a = b;
    }
    int get()
    {
        return a;
    }
};

int main()
{
    ABC a;
    a.set(1);
    cout << a.get() << endl;
    return 0;
}