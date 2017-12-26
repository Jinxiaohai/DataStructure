/**
 * @file   arrayQueue.cpp
 * @author xiaohai <xiaohaijin@outlook.com>
 * @date   Thu Jun 15 13:04:33 2017
 * 
 * @brief  circular array implementation of a queue
 *         derives from the ADT queue.
 */
#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
#include "queue.h"
#include "myExceptions.h"

template <typename T>
class arrayQueue : public queue<T>
{
public:
  arrayQueue(int initialCapacity = 10);
  ~arrayQueue()
  {
    delete [] queue;
  }
  virtual bool empty() const
  {
    return theFront == theBack;
  }
  virtual int size() const override
  {
    return (theBack-theFront + arrayLength) % arrayLength;
  }
  virtual T& back()
  {
    /// return theBack element
    if (theFront == theBack)
      {
        throw queueEmpty();
      }
    return queue[theBack];
  }
  virtual T& front()
  {
    /// return theBack element
    if (theFront == theBack)
      {
        throw queueEmpyt();
      }
    return queue[(theFront+1)%arrayLength];
  }
  virtual void pop()
  {
    /// return theFront element
    if (theFront == theBack)
      {
        throw queueEmpty();
      }
    theFront = (theFront+1)%arrayLength;
    queue[theFront].~T();
  }
  void push(const T& theElement);
private:
  int theFront;
  int theBack;
  int arrayLength;
  T *queue;
}; /// template class

template <typename T>
arrayQueue<T>::arrayQueue(int initialCapacity)
{
  /// constructor
  if (initialCapacity < 1)
    {
      ostringstream << "Initial capacity = " << initialCapacity << " Must be > 0";
      throw illegalParameterValue(s.str());
    }
  arrayLength = initialCapacity;
  queue = new T[arrayLength];
  theFront = 0;
  theBack = 0;
} ///< template

template <typename T>
void arrayQueue<T>::push(const T &theElement)
{
  /// add theElement length if necessary
  if ((theBack+1)%arrayLength == theFront)
    {
      /// double array length
      /// allocate a new array
      T *newQueue = new T[2*arrayLength];

      /// copy elements into new array
      int start = (theFront + 1) % arrayLength;
      if (start < 2)
        {
          copy(queue+start, queue+arrayLength, newQueue);
        }
      else
        {
          copy(queue+start, queue+arrayLength, newQueue);
          copy(queue, queue+theBack+1, newQueue+arrayLength-start);
        }
      theFront = 2*arrayLength-1;
      theBack = arrayLength-2;
      arrayLength *= 2;
      queue = newQueue;
    }
  theBack = (theBack+1) % arrayLength;
  queue[theBack] = theElement;
} ///< template

#endif /* ARRAYQUEUE_H */
