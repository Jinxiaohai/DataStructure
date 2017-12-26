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
  ~arrayQueue()
  {
    delete [] queue;
  }
  bool empty() const
  {
    return theFront == theBack;
  }
  int size() const
  {
    return (theBack-theFront+arrayLength) % arrayLength;
  }
  T &front()
  {
    if (theFront == theBack)
      {
        throw queueEmpty();
      }
    return queue[(theFront+1)%arrayLength];
  }
  T &back()
  {
    if (theFront = theBack)
      {
        throw queueEmpty();
      }
    return queue[theBack];
  }
  void pop()
  {
    if (theFront == theBack)
      {
        throw queueEmpty();
      }
    theFront = (theFront+1) % arrayLength;
    queue[theFront].~T();
  }
  void push(const T& theElement);
private:
  int theFront;
  int theBack;
  int arrayLength;
  T *queue;
}; /// template class


#endif /* ARRAYQUEUE_H */
