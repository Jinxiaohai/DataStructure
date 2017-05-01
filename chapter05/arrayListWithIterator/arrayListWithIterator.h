/**
 * @file   arrayListWithIterator.cpp
 * @author xiaohai <xiaohaijin@outlook.com>
 * @date   Mon May  1 15:15:59 2017
 * 
 * @brief  array implementation of a linear list
 *         derives from abstract class linearList just
 *         to make sure all method of the ADT are implemented uses
 *         STL algorithms to simplify code iterator class for arrayList included
 */

#ifndef ARRAYLISTWITHITERATOR_H
#define ARRAYLISTWITHITERATOR_H

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iterator>
#include "Exceptions.h"
#include "linearList.h"
#include "changeLength1D.h"
using namespace std;

namespace xiaohai
{
  template <typename T>
  class arrayList : public linearList<T>
  {
  public:
    /// constuctor, copy constuctor and destructor
    arrayList(int initialCapacity = 10);
    arrayList(const arrayList<T>&);
    ~arrayList()
    {
      delete [] element;
    }

    /// ADT methods
    bool empty() const
    {
      return listSize == 0;
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

    /// additional method
    int capacity() const
    {
      return arrayLength;
    }

    /// iterator to start and end of list
    class iterator;
    iterator begin()
    {
      return iterator(element);
    }
    iterator end()
    {
      return iterator(element+listSize);
    }
    /// iterator for arrayList
    class iterator
    {
    public:
      /// typedefs requires by c++ for a bidirectional iterator
      typedef bidirectional_iterator_tag iterator_category;
      typedef T value_type;
      typedef ptrdiff_t difference_type;
      typedef T* pointer;
      typedef T& reference;

      /// constuctor
      iterator(T* thePosition = 0)
      {
        position = thePosition;
      }
      /// dereferencing operators
      T& operator*() const
      {
        return *position;
      }
      T* operator->() const
      {
        return &*position;
      }
      /// increment
      iterator& operator++() /// preincrement
      {
        ++position;
        return *this;
      }
      iterator operator++(int) /// postincrement
      {
        iterator old = *this;
        ++position;
        return old;
      }
      /// decrement
      iterator& operator--() /// predecrement
      {
        --position;
        return *this;
      }
      iterator operator--(int) /// postdecrement
      {
        iterator old = *this;
        --position;
        return old;
      }

      /// equality testing
      bool operator!=(const iterator right) const
      {
        return position != right.position;
      }
      bool operator==(const iterator right) const
      {
        return !operator!=(right);
      }
        
    protected:
      T* position;
    };/// end of iterator class

    
    /// additional members of arrayList
  protected:
    void checkIndex(int theIndex) const;
    T* element;
    int arrayLength;
    int listSize;
  }; /// template class
}



namespace xiaohai
{
  template <typename T>
  arrayList<T>::arrayList(int initialCapacity)
  {
    /// constuctor
    if (initialCapacity < 1)
      {
        ostringstream s;
        s << "initial capacity= " << initialCapacity << " must be > 0";
        throw illegalParameterValue(s.str());
      }
    arrayLength = initialCapacity;
    element = new T[arrayLength];
    listSize = 0;
  } /// template

  template <typename T>
  arrayList<T>::arrayList(const arrayList<T>& theList)
  {
    /// copy constuctor
    arrayLength = theList.arrayLength;
    listSize = theList.listSize;
    element = new T[arrayLength];
    copy(theList.element, theList.element+listSize, element);
  } /// template

  template <typename T>
  void arrayList<T>::checkIndex(int theIndex) const
  {
    /// verify that theIndex is between 0 and listSize-1
    if (theIndex < 0 || theIndex >= listSize)
      {
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
      }
  } /// template

  template <typename T>
  T& arrayList<T>::get(int theIndex) const
  {
    /// return element whose index is theIndex
    /// throw illegalindex exception if no such element
    checkIndex(theIndex);
    return element[theIndex];
  } /// template

  template <typename T>
  int arrayList<T>::indexOf(const T& theElement) const
  {
    /// return index of first occurrence of theElement
    /// return -1 if theElement not in list
    /// search for theElement
    int theIndex = (int) (find(element, element+listSize, theElement) - element);
    /// check if theElement was found
    if (theIndex == listSize)
      {
        return -1;
      }
    else
      {
        return theIndex;
      }
  }

  template <typename T>
  void arrayList<T>::erase(int theIndex)
  {
    /// delete the element whose index is theIndex
    /// throw illegalindex exception if no such element
    checkIndex(theIndex);

    /// valid index, shift elements with higher index
    copy(element+theIndex+1, element+listSize, element+theIndex);
    element[--listSize].~T();
  } /// template

  template <typename T>
  void arrayList<T>::insert(int theIndex, const T &theElement)
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
    copy_backward(element+theIndex, element+listSize, element+listSize+1);
    element[theIndex] = theElement;
    ++listSize;
  } /// template

  template <typename T>
  void arrayList<T>::output(ostream &out) const
  {
    /// put the list into the stream out.
    copy(element, element+listSize, ostream_iterator<T>(cout, "  "));
  } /// template

  template <typename T>
  ostream& operator<<(ostream& out, const arrayList<T>& x)
  {
    x.output(out);
    return out;
  } /// template
}

#endif /* ARRAYLISTWITHITERATOR_H */
