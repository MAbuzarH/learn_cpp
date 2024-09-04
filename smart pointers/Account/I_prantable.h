#ifndef _I_PRANTABLE_H_
#define _I_PRANTABLE_H_
#include <iostream>
#include <string>

class I_Prantable
{
  friend std::ostream &operator<<(std::ostream &os, const I_Prantable &obj);

public:
  virtual void print(std::ostream &os) const = 0;
  virtual ~I_Prantable() = default;
};

#endif