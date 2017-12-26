#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class queue
{
public:
  virtual ~queue() { }
  /// return true if the queue is empty.
  virtual bool empty() const = 0;
  virtual int size() const = 0;
  virtual T& front() = 0;
  virtual T& back() = 0;
  virtual void pop() = 0;
  virtual void push(const T& theElement) = 0;
}; /// template class

#endif /* QUEUE_H */
