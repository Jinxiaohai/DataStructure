/**
 * @file   arrayListNoSTL.cpp
 * @author xiaohai <xiaohaijin@outlook.com>
 * @date   Sun Apr 30 21:54:00 2017
 * 
 * @brief  array implementation of a linear list
 *         derives from abstract class linearList just to
 *         make sure all methods of the ADT are implementated
 *         code does not use STL algorithms.
 */

#ifndef ARRAYLISTNOSTL_H
#define ARRAYLISTNOSTL_H

#include <iostream>
#include <sstream>
#include <string>
#include "linearList.h"
#include "Exceptions.h"
#include "changeLength1D.h"
using namespace std;

namespace xiaohai
{
  template <typename T>
  class arrayListNoSTL : public linearList<T>
  {
  public:
    /// constructor, copy constructor and destructor
    arrayListNoSTL(int initialCapacity = 10);
    arrayListNoSTL(const arrayListNoSTL<T>&);
    ~arrayListNoSTL()
    {
      delete [] element;
    }

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

    /// additonal method
    int capacity() const
    {
      return arrayLength;
    }
    

    
  protected:
    void checkIndex(int theIndex) const;
    /// throw illegallIndex if theIndex invalid
    T *element;
    int arrayLength;
    int listSize;
  }; /// template class
}

namespace xiaohai
{
  template <typename T>
  arrayListNoSTL<T>::arrayListNoSTL(int initialCapacity)
  {
    /// constructor
    if (initialCapacity < 1)
      {
        ostringstream s;
        s << "Initial capacity = " << initialCapacity << "must be > 0";
        throw illegalParameterValue(s.str());
      }
    arrayLength = initialCapacity;
    element = new T[arrayLength];
    listSize = 0;
  } /// template

  template <typename T>
  arrayListNoSTL<T>::arrayListNoSTL(const arrayListNoSTL<T>& theList)
  {
    /// copy constructor
    arrayLength = theList.arrayLength;
    listSize = theList.listSize;
    element = new T[arrayLength];
    /// copy the list elements
    for (int i = 0; i != listSize; ++i)
      {
        element[i] = theList.element[i];
      }
  } /// template

  template <typename T>
  void arrayListNoSTL<T>::checkIndex(int theIndex) const
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
  T& arrayListNoSTL<T>::get(int theIndex) const
  {
    /// return element whose index is theIndex.
    /// Throw illegalindex exception if no such element.
    checkIndex(theIndex);
    return element[theIndex];
  } /// template

  template <typename T>
  int arrayListNoSTL<T>::indexOf(const T &theElement) const
  {
    /// return index of first occurrence of theElement.
    /// return -1 if theElement not in list.
    /// search for theelement
    for (int i = 0; i != listSize; ++i)
      {
        if (element[i] == theElement)
          {
            return i;
          }
      }
    return -1;
  } /// template

  template <typename T>
  void arrayListNoSTL<T>::erase(int theIndex)
  {
    /// delete the element whose index is theIndex
    /// throw illegalindex exception if no such element
    checkIndex(theIndex);

    /// valid index, shift elements with higher index
    for (int i = theIndex+1; i != listSize; ++i)
      {
        element[i-1] = element[i];
      }
    /// destructor for T
    element[--listSize].~T();
  } /// template

  template <typename T>
  void arrayListNoSTL<T>::insert(int theIndex, const T &theElement)
  {
    /// insert theElement so that its index is theIndex
    if (theIndex < 0 || theIndex > listSize)
      {
        /// invalid index
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
      }
    /// valid index, make sure we have space
    if (listSize == arrayLength)
      {
        /// no space, double capacity
        changeLength1D(element, arrayLength, 2*arrayLength);
        arrayLength *= 2;
      }
    /// shift elements right one position
    for (int i = listSize-1; i != theIndex-1; --i)
      {
        element[i+1] = element[i];
      }
    
    element[theIndex] = theElement;
    ++listSize;
  } /// template

  template <typename T>
  void arrayListNoSTL<T>::output(ostream &out) const
  {
    /// put the list into the stream out.
    for (int i = 0; i < listSize; ++i)
      {
        out << element[i] << "  ";
      }
  } /// template

  template <typename T>
  ostream& operator<<(ostream& out, const arrayListNoSTL<T>& x)
  {
    x.output(out);
    return out;
  } /// template
  
}
#endif /* ARRAYLISTNOSTL_H */
