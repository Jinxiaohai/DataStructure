/**
 * @file   arrayStack.cpp
 * @author xiaohai <xiaohaijin@outlook.com>
 * @date   Thu Jun  1 20:25:46 2017
 * 
 * @brief  array implementation of a stack
 *         derives from the ADT stack
 */
#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include "stack.h"
#include "myExceptions.h"
#include "changeLength1D.h"
#include <sstream>

template <typename T>
class arrayStack : public stack<T>
{
public:
  arrayStack(int initialCapacity = 10);
  ~arrayStack()
  {
    delete [] stack;
  }
  bool empty() const
  {
    return stackTop == -1;
  }
  int size() const
  {
    return stackTop+1;
  }
  T &top()
  {
    if (stackTop == -1)
      {
	throw stackEmpty();
      }
    return stack[stackTop];
  }
  void pop()
  {
    if (stackTop == -1)
      {
	throw stackEmpty();
      }
    stack[stackTop--].~T();
  }
  void push(const T& theElement);
private:
  int stackTop;
  int arrayLength;
  T *stack;
}; /// template class

template <typename T>
arrayStack<T>::arrayStack(int initialCapacity)
{
  /// constructor
  if (initialCapacity < 1)
    {
      ostringstream s;
      s << "Initial capacity = " << initialCapacity << " Must be > 0";
      throw illegalParameterValue(s.str());
    }
  arrayLength = initialCapacity;
  stack = new T[arrayLength];
  /// top size is -1.
  stackTop = -1;
} ///< template

template <typename T>
void arrayStack<T>::push(const T &theElement)
{
  /// add theElement to stack
  if (stackTop == arrayLength-1)
    {
      /// nospace, double capacity
      changeLength1D(stack, arrayLength, 2*arrayLength);
      arrayLength *= 2;
    }
  stack[++stackTop] = theElement;
} ///< template

#endif /* ARRAYSTACK_H */
