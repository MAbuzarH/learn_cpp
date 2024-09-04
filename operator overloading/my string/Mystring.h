#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
using namespace std;

class Mystring
{
  // friend bool operator==(const Mystring &lhs, const Mystring &rhs);
  // friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);
  // friend Mystring operator-(const Mystring &obj);
  friend ostream &operator<<(ostream &os, const Mystring &obj);
  friend istream &operator>>(istream &in, Mystring &obj);

private:
  char *str;

public:
  // constrctures
  Mystring();                       // no arg constructor
  Mystring(const char *s);          // default   constructor
  Mystring(const Mystring &source); // copy constructor
  Mystring(Mystring &&source);

  // opreator overloading
  // copy assignment
  Mystring &operator=(const Mystring &rhs);
  Mystring operator-() const;
  Mystring operator+(const Mystring &rhs) const;
  bool operator==(const Mystring &rhs) const;
  // move assignment
  Mystring &operator=(Mystring &&rhs);
  ~Mystring();

  void display() const;
  int get_length() const;
  const char *get_str() const;
};

#endif
