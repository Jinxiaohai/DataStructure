/**
 * @file   chain.cpp
 * @author xiaohai <xiaohaijin@outlook.com>
 * @date   Mon May  1 21:06:19 2017
 * 
 * @brief  linked implementation of a linear list
 *         derives from abstract class linearList
 *         just to make sure all methods of the ADT
 *         are implementated.
 */
#ifndef CHAIN_H
#define CHAIN_H

#include <iostream>
#include <sstream>
#include <string>
#include "linearList.h"
#include "Exceptions.h"
#include "chainNode.h"

using namespace std;

namespace xiaohai
{
  /// 前向声明的两个类。
  class linkedDigraph;
  template <typename T> class linkedWDigraph;
  
  template <typename T>
  class chain : public linearList<T>
  {
    /// 友员类
    friend linkedDigraph;
    friend linkedWDigraph<int>;
    friend linkedWDigraph<float>;
    friend linkedWDigraph<double>;

  public:
    /// constructor, copy constructor and destructor
    chain(int initialCapacity = 10);
    chain(const chain<T>&);
    ~chain();

    /// ADT methods
    bool empty() const
    {
      return listSize ==0;
    }
    int size() const
    {
      return listSize;
    }
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(ostream& out) const;

  protected:
    /// throw illegalIndex if theIndex invalid
    void checkIndex(int theIndex) const;
    /// pointer to first node in chain
    chainNode<T>* firstNode;
    /// number of elements in list
    int listSize;
  }; /// template class
}

namespace xiaohai
{
  template <typename T>
  chain<T>::chain(int initialCapacity)
  {
    /// constructor
    if (initialCapacity < 1)
      {
        ostringstream s;
        s << "Initial capacity = " << initialCapacity << " must be > 0";
        throw illegalParameterValue(s.str());
      }
    firstNode = NULL;
    listSize = 0;
  } /// template

  template <typename T>
  chain<T>::chain(const chain<T>& theList)
  {
    /// copy constructor
    listSize = theList.listSize;

    if (listSize == 0)
      {
        /// theList is empty
        firstNode = NULL;
        return;
      }

    /// no empty list
    /// node in theList to copy from
    chainNode<T>* sourceNode = theList.firstNode;
    /// copy first element of theList
    firstNode = new chainNode<T>(sourceNode->element);
    /// current last node in *this
    sourceNode = sourceNode->next;
    chainNode<T>* targetNode = firstNode;

    /// 循环到倒数第一个元素
    while (sourceNode != NULL)
      {
        /// copy remaining elements
        targetNode->next = new chainNode<T>(sourceNode->element);
        /// targetNode是遍历目标链的指针操作
        targetNode = targetNode->next;
        /// sourcenode是遍历源链的指针操作
        sourceNode = sourceNode->next;
      }
    targetNode->next = NULL;
  } /// template

  template <typename T>
  chain<T>::~chain()
  {
    /// chain destructor. delete all nodes in chain
    while (firstNode != NULL)
      {
        /// delete firstNode
        chainNode<T>* nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
      }
  } /// template

  template <typename T>
  void chain<T>::checkIndex(int theIndex) const
  {
    /// verify that theIndex is between 0 and listsize-1
    if (theIndex < 0 || theIndex >= listSize)
      {
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
      }
  } /// template

  template <typename T>
  T& chain<T>::get(int theIndex) const
  {
    /// return element whose index id theIndex
    /// throw illegalindex exception if no such element
    checkIndex(theIndex);

    /// move to desired node
    chainNode<T>* currentNode = firstNode;
    for (int i = 0; i != theIndex; ++i)
      {
        currentNode = currentNode->next;
      }
    return currentNode->element;
  } /// template

  template <typename T>
  int chain<T>::indexOf(const T& theElement) const
  {
    /// return index of first occurrence of theElement
    /// return -1 if theElement not in list
    /// search the chain for theElement
    chainNode<T>* currentNode = firstNode;
    int index = 0;
    while (currentNode != NULL && currentNode->element != theElement)
      {
        /// move to next node
        currentNode = currentNode->next;
        ++index;
      }
    /// make sure we found matching element
    if (currentNode == NULL)
      {
        return -1;
      }
    else
      {
        return index;
      }
  } /// template

  template <typename T>
  void chain<T>::erase(int theIndex)
  {
    /// delete the element whose index is theIndex
    /// throw illegalindex exception if no such element
    checkIndex(theIndex);

    /// valid index, locate node with element to delete
    chainNode<T>* delelteNode;
    if (theIndex == 0)
      {
        /// remove first node from chain
        delelteNode = firstNode;
        firstNode = firstNode->next;
      }
    else
      {
        /// use p to get to predecessor of desired node
        chainNode<T>* p = firstNode;
        for (int i = 0; i != theIndex-1; ++i)
          {
            p = p->next;
          }
        delelteNode = p->next;
        /// remove deleltenNode from chain
        p->next = p->next->next;
      }
    --listSize;
    delete delelteNode;
  } /// template

  template <typename T>
  void chain<T>::insert(int theIndex, const T &theElement)
  {
    /// insert theElement so that its index is theIndex
    if (theIndex < 0 || theIndex > listSize)
      {
        /// invalid index
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
      }
    if (theIndex == 0)
      {
        /// insert at front
        firstNode = new chainNode<T>(theElement, firstNode);
      }
    else
      {
        /// find predecessor of new element
        chainNode<T>* p = firstNode;
        for (int i = 0; i != theIndex-1; ++i)
          {
            p = p->next;
          }
        /// insert after p
        p->next = new chainNode<T>(theElement, p->next);
      }
    ++listSize;
  } /// template

  template <typename T>
  void chain<T>::output(ostream &out) const
  {
    /// put the list into the stream out.
    for (chainNode<T>* currentNode = firstNode; currentNode != NULL;
         currentNode = currentNode->next)
      {
        out << currentNode->element << "  ";
      }
  } /// template

  /// overload <<
  template <typename T>
  ostream& operator<<(ostream& out, const chain<T>& x)
  {
    x.output(out);
    return out;
  } /// template
}
#endif /* CHAIN_H */
