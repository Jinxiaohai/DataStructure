/**
 * @file   arrayQueue.cpp
 * @author xiaohai <xiaohaijin@outlook.com>
 * @date   Fri Jun  2 09:11:40 2017
 * 
 * @brief  circular array implementation of a queue
 *         dirives from the ADT queue
 */
#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include "queue.h"
#include "myExceptions.h"
#include <sstream>

using namespace std;

template <typename T>
class arrayQueue : public queue<T>
{
public:
  arrayQueue(int initialCapacity = 10);
  ~arrayQueue() { delete [] queue;}
  /// empty
  bool empty() const
  {
    return theFront == theBack;
  }
  /// size
  int size() const
  {
    return (theBack-theFront+arrayLength) % arrayLength;
  }
  /// front
  T& front()
  {
    /// return front element
    if (theFront == theBack)
      {
	throw queueEmpty();
      }
    return queue[(theFront+1)%arrayLength];
  }
  /// back
  T& back()
  {
    /// return theBack element
    if (theFront == theBack)
      {
	throw queueEmpty();
      }
    return queue[theBack];
  }
  /// remove
  void pop()
  {
    if (theFront == theBack)
      {
	throw queueEmpty();
      }
    theFront = (theFront + 1) % arrayLength;
    queue[theFront].~T();
  }
  /// push
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
      ostringstream s;
      s << "Initial capacity = " << initialCapacity << " Must be > 0";
      throw illegalParameterValue(s.str());
    }
  arrayLength = initialCapacity;
  queue = new T[arrayLength];
  theFront = 0;
  theBack = 0;
} ///< template

template <typename T>
void arrayQueue<T>::push(const T& theElement)
{
  /// add theElement to queue
  /// increase array length if necessary
  if ((theBack+1)%arrayLength == theFront)
    {
      /// double array length
      T* newQueue = new T[2*arrayLength];
      /// copy elements into new array
      int start = (theFront+1) % arrayLength;
      if (start < 2)
	{
	  copy(queue+start, queue+start+arrayLength-1, newQueue);
	}
      else
	{
	  /// queue wraps around
	  copy(queue+start, queue+arrayLength, newQueue);
	  copy(queue, queue+theBack+1, newQueue+arrayLength-start);
	}
      theFont = 2*arrayLength-1;
      theBack = arrayLength-2;
      arrayLength *= 2;
      queue = newQueue;
    }
  theBack = (theBack+1)%arrayLength;
  queue[theBack] = theElement;
} ///< template

#endif /* ARRAYQUEUE_H */
