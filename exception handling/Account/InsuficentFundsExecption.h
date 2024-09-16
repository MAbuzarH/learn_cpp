#include <iostream>
// #include <exception>

using namespace std;

#ifndef _INSUFICENTFUNDSEXECPTION_H_
#define _INSUFICENTFUNDSEXECPTION_H

class InsuficentFundsExecption : public std::exception
{
public:
    InsuficentFundsExecption()
    {
    }
    virtual const char *What() const noexcept
    {
        return "Your Balance is insuficent";
    }
    ~InsuficentFundsExecption() {}
};

#endif