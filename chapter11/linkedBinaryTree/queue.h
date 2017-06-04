/**
 * @file   queue.cpp
 * @author xiaohai <xiaohaijin@outlook.com>
 * @date   Fri Jun  2 09:02:47 2017
 * 
 * @brief  abstact class queue
 *         abstact data type specification for queue data structure
 *         all methods are pure virtual functions
 */
#ifndef QUEUE_H
#define QUEUE_H

using namespace std;

template <typename T>
class queue
{
public:
  virtual ~queue() {}
  /// return true if queue is empty
  virtual bool empty() const = 0;
  /// return number of elements in queue
  virtual int size() const = 0;
  /// return reference to the front element
  virtual T& front() = 0;
  /// return reference to the back element
  virtual T& back() = 0;
  /// remove the front element
  virtual void pop() = 0;
  /// add theElement at the back of the queue
  virtual void push(const T& theElement) = 0;
}; /// template class

#endif /* QUEUE_H */
