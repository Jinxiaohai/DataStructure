/**
 * @file   linkedQueue.cpp
 * @author xiaohai <xiaohaijin@outlook.com>
 * @date   Thu Jun 15 14:02:09 2017
 * 
 * @brief  linked implementation of a queue
 *         derives from the ADT queue.
 */
#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <sstream>
#include "queue.h"
#include "chainNode.h"
#include "myExceptions.h"

using namespace std;

template <typename T>
class linkedQueue : public queue<T>
{
public:
  linkedQueue(int initialCapacity = 10)
  {
    queueFront = NULL;
    queueSize = 0;
  }
  ~linkedQueue();
  bool empty() const
  {
    return queueSize == 0;
  }
  int size() const
  {
    return queueSize;
  }
  T& front()
  {
    if (queueSize == 0)
      {
        throw queueEmpty();
      }
    return queueFront->element;
  }
  T& back()
  {
    if (queueSize == 0)
      {
        throw queueEmpty();
      }
    return queueBack->element;
  }
  void pop();
  void push(const T&);
  
private:
  chainNode<T>* queueFront;
  chainNode<T>* queueBack;
  int queueSize;
}; /// template class

template <typename T>
linkedQueue<T>::~linkedQueue()
{
  /// destructor, 从头开始析构。
  while (queueFront != NULL)
    {
      chainNode<T> *nextNode = queueFront->next;
      delete queueFront;
      queueFront = nextNode;
    }
} ///< template

template <typename T>
void linkedQueue<T>::pop()
{
  /// delete front element
  if (queueFront == NULL)
    {
      throw queueEmpty();
    }
  chainNode<T>* nextNode = queueFront->next;
  delete queueFront;
  queueFront = nextNode;
  --queueSize;
} ///< template

template <typename T>
void linkedQueue<T>::push(const T& theElement)
{
  chainNode<T>* newNode = new chainNode<T>(theElement, NULL);
  if (queueSize == 0)
    {
      queueFront = newNode;
    }
  else
    {
      queueBack->next = newNode;
    }
  queueBack = newNode;
  ++queueSize;
} ///< template

#endif /* LINKEDQUEUE_H */
