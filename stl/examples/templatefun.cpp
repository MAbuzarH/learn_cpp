#include <iostream>
#include <string>

using namespace std;

template <typename T>
T myMin(T a, T b) // Renaming the function to avoid conflict with std::min
{
    return (a < b) ? a : b;
}

template <typename T1, typename T2>
void fun(T1 a, T2 b)
{
    cout << a << " " << b << " " << endl;
}

struct Person
{
    string name;
    int age;
    bool operator<(const Person &rhs) const
    {
        return this->age < rhs.age;
    }
};
ostream &operator<<(ostream &os, const Person &p)
{
    os << p.name;
    return os;
}

template <typename T>
void my_swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
int main()
{
    int x = 100;
    int y{200};
    my_swap(x, y);
    cout << x << " " << y << endl;
    Person p1{"moe", 40};
    Person p2{"curly", 30};
    Person p3 = myMin(p1, p2);
    cout << p3.name << " " << p3.age << endl;

    int a = 8;
    double b = 1.0;
    fun<int, double>(a, b);
    fun<Person, double>(p1, b);
    cout << myMin<int>(19, 10) << endl; // Using the renamed function

    return 0;
}
