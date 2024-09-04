#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
using namespace std;

class Mystring
{
    friend ostream &operator<<(ostream &os, const Mystring &obj);
    friend istream &operator>>(istream &in, Mystring &obj);
  

private:
    char *str;

public:
    // constructors
    Mystring();                           // constrcture with no arg
    Mystring(const char *s);              // default constructor
    Mystring(const Mystring &source);     // copy constructor
    Mystring(Mystring &&source) noexcept; // move constructor

    // setter
    void set_str(const char *s);

    // getter
    const char *get_str() const;
    int get_length() const;

    // operator overload
    Mystring &operator=(const Mystring &rhs); // copy assignment
    Mystring &operator=(Mystring &&rhs);      // move assignment
    Mystring operator-() const;
    Mystring operator+(const Mystring &obj) const;
    Mystring &operator+=(const Mystring &obj);
    Mystring &operator++(); // pree increment
    Mystring operator++(int);
    Mystring operator*(int n) const;

    bool operator==(const Mystring &rhs) const;
    bool operator!=(const Mystring &rhs) const;
    bool operator>(const Mystring &rhs) const;
    bool operator<(const Mystring &rhs) const;
    void display() const; // to display string
    ~Mystring();
};

#endif