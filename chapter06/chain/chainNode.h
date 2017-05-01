/**
 * @file   chainNode.cpp
 * @author xiaohai <xiaohaijin@outlook.com>
 * @date   Mon May  1 20:49:34 2017
 * 
 * @brief  chain node
 */

#ifndef CHAINNODE_H
#define CHAINNODE_H

namespace xiaohai
{
  template <typename T>
  struct chainNode
  {
    /// data members
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
}
#endif /* CHAINNODE_H */
