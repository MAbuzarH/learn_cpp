#include <iostream>

using namespace std;

class B;
class C;
class A
{
public:
    int Aa;
    int Ab;
    void displayA()
    {
        cout << " in a: " << endl;
       
    }
};

class B
{
public:
    friend class A;
    int Ba;
    int Bb;
    void displayB()
    {
        cout << " in b: " << endl;
        
    }
};

class C
{
public:
    int Ca;
    int Cb;
    void displayC()
    {
        cout << " in c: " << endl;
    }
    friend class B;
};

int main()
{

    B b;
    b.displayB();
    return 0;
}