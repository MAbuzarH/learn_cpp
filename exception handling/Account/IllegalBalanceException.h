#include <iostream>
// #include <exception>

using namespace std;

#ifndef _ILLEGALBALANCEEXCEPTION_H_
#define _ILLEGALBALANCEEXCEPTION_H

class IllegalBalanceException : public std::exception
{
public:
    IllegalBalanceException()
    {
    }
    virtual const char *What() const noexcept
    {
        return "Illegal Bal";
    }
    ~IllegalBalanceException() = default;
};

#endif