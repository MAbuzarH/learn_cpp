#include <iostream>
#include <stdio.h>
using namespace std;
template<class T>
class  Arthamatic
{
private:
    T a;
    T b;

public:
    Arthamatic(T a, T b);
    T add();
    T sub();
};

template<class T>
Arthamatic<T>::Arthamatic(T a, T b)
{
    this->a = a;
    this->b = b;
}

template<class T>
T Arthamatic<T>::add()
{
    T c = 0;
    c = this->a + this->b;
    return c;
}

template<class T>
T Arthamatic<T>::sub()
{
    T c = 0;
    c = this->a - this->b;
    return c;
}
int main()
{
    Arthamatic<int> a1{10, 20};
    cout << a1.add() << endl;
    return 0;
}
