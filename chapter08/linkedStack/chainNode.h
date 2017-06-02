#ifndef CHAINNODE_H
#define CHAINNODE_H

template <typename T>
struct chainNode
{
  T element;
  chainNode<T> *next;

  /// methods
  chainNode() {}
  chainNode(const T& element)
  {
    this->element = element;
  }
  chainNode(const T& element, chainNode<T>* next)
  {
    this->element = element;
    this->next = next;
  }
}; /// template class

#endif /* CHAINNODE_H */
