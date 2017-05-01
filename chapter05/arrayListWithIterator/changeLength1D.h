#ifndef CHANGELENGTH1D_H
#define CHANGELENGTH1D_H

#include "Exceptions.h"
using namespace std;

namespace xiaohai
{
  template <typename T>
    /// 
    void changeLength1D(T* &a, int oldLength, int newLength)
    {
      if (newLength < 0)
        {
          throw illegalParameterValue("new length must be > 0");
        }
      T* temp = new T[newLength];
      int number = min(oldLength, newLength);
      /// copy [a, a+number) to temp
      copy(a, a+number, temp);
      delete [] a;
      a = temp;
    } /// template
}

#endif /* CHANGELENGTH1D_H */
