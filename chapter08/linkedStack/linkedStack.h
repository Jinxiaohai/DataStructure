#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

#include <sstream>
#include "stack.h"
#include "chainNode.h"
#include "myExceptions.h"

using namespace std;

template <typename T>
class linkedStack : public stack<T>
{
public:
  linkedStack(int initialCapacity = 10)
  {
    stackTop = NULL;
    stackSize = 0;
  }
  ~linkedStack();
  bool empty() const
  {
    return stackSize == 0;
  }
  int size() const
  {
    return stackSize;
  }
  T& top()
  {
    if (stackSize == 0)
      {
	throw stackEmpty();
      }
    return stackTop->element;
  }
  void pop();
  void push(const T& theElement)
  {
    /// be careful
    stackTop = new chainNode<T>(theElement, stackTop);
    ++stackSize;
  }
private:
  chainNode<T>* stackTop;
  int stackSize;
}; /// template class

template <typename T>
linkedStack<T>::~linkedStack()
{
  /// Destructor
  while (stackTop != NULL)
    {
      /// delete top node
      chainNode<T>* nextNode = stackTop->next;
      delete stackTop;
      stackTop = nextNode;
    }
} ///< template

template <typename T>
void linkedStack<T>::pop()
{
  /// delete top element
  if (stackSize == 0)
    {
      throw stackEmpty();
    }
  chainNode<T>* nextNode = stackTop->next;
  delete stackTop;
  stackTop = nextNode;
  --stackSize;
} ///< template
#endif /* LINKEDSTACK_H */
