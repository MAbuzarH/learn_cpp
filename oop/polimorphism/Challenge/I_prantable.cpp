#include <iostream>
#include "I_prantable.h"
using namespace std;
ostream &operator<<(ostream &os, const I_Prantable &obj)
{
   obj.print(os);
   return os;
}