/**
 * @file   derivedArrayStack.cpp
 * @author xiaohai <xiaohaijin@outlook.com>
 * @date   Thu Jun  1 20:15:28 2017
 * 
 * @brief  array stack derived from arrayList
 *         derives from abstract class stack just 
 *         to make sure all methods of the ADT are implemented
 */

#ifndef DERIVEDARRAYSTACK_H
#define DERIVEDARRAYSTACK_H

#include "arrayList.h"
#include "stack.h"
#include "myExceptions.h"

using namespace std;
template <typename T>
class derivedArrayStack : private arrayList<T>, public stack<T>
{
public:
  derivedArrayStack(int initialCapacity = 10):arrayLis<T> (initialCapacity) { }
  bool empty() const
  {
    return arrayList<T>::empty();
  }
  int size() const
  {
    return arrayList<T>::size();
  }
  T& top()
  {
    if (arrayList<T>::empty())
      {
	throw stackEmpty();
      }
    return get(arrayList<T>::size()-1);
  }
  void pop()
  {
    if (arrayList<T>::empty())
      {
	throw stackEmpty();
      }
    erase(arrayList<T>::size()-1);
  }
  void push(const T& theElement)
  {
    insert(arrayList<T>::size(), theElement);
  }
}; /// template class

#endif /* DERIVEDARRAYSTACK_H */
