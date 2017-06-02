/**
 * @file   stack.cpp
 * @author xiaohai <xiaohaijin@outlook.com>
 * @date   Thu Jun  1 20:05:50 2017
 * 
 * @brief  abstract class stack
 *         abstract data type specification for stack data structure
 *         all methods are pure virtual functions.
 */

#ifndef STACK_H
#define STACK_H

using namespace std;
template <typename T>
class stack
{
 public:
  virtual ~stack() {}
  /// return true if stack is empty
  virtual bool empty() const = 0;
  /// return number of element in stack
  virtual int size() const = 0;
  /// return reference to the top element
  virtual T& top() = 0;
  /// remove the top element
  virtual void pop() = 0;
  /// insert theElement at the top of the stack
  virtual void push(const T& theElement) = 0;
}; /// template class

#endif /* STACK_H */
