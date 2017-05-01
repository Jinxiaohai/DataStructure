/**
 * @file   arrayList.h
 * @author xiaohai <xiaohaijin@outlook.com>
 * @date   Sat Apr 29 21:33:33 2017
 * 
 * @brief  array implementation of a linear list
 *         derives from abstract class linearList just to make sure
 *         all methods of the ADT are implemented
 *         USES STL ALGORITHMS TO SIMPLIFY CODE
 */

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iterator>
#include "linearList.h"
#include "Exceptions.h"
#include "changeLength1D.h"
using namespace std;

namespace xiaohai
{
  template <typename T>
  class arrayList : public linearList<T>
  {
  public:
    /// constructor, copy constructor and destructor
    arrayList(int initialCapacity = 10);
    arrayList(const arrayList<T>&);
    ~arrayList()
    {
      delete [] element;
    }

    /// ADT method
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
  
  private:
    void checkIndex(int theIndex) const;
    T* element;
    int arrayLength;
    int listSize;
  }; /// template class

  template <typename T>
  arrayList<T>::arrayList(int initialCapacity)
  {
    /// constructor
    if (initialCapacity < 1)
      {
        ostringstream s;
        s << "Initial capacity = " << initialCapacity << " must be > 0";
        throw illegalParameterValue(s.str());
      }
    arrayLength = initialCapacity;
    element = new T[arrayLength];
    listSize = 0;
  } /// template

  template <typename T>
  arrayList<T>::arrayList(const arrayList<T>& theList)
  {
    /// copy constructor
    arrayLength = theList.arrayLength;
    listSize = theList.listSize;
    element = new T[arrayLength];
    /// copy elements.
    copy(theList.element, theList.element+listSize, element);
  } /// template

  template <typename T>
  void arrayList<T>::checkIndex(int theIndex) const
  {
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
    checkIndex(theIndex);
    return element[theIndex];
  } /// template

template <typename T>
int arrayList<T>::indexOf(const T &theElement) const
{
  /// find the first element that equal the element. if not find in the container
  /// return the last.
  int theIndex = (int) (find(element, element+listSize, theElement)-element);
  /// check if theElement was found
  if (theIndex == listSize)
    {
      return -1;
    }
  else
    {
      return theIndex;
    }
} /// template

  template <typename T>
  void arrayList<T>::erase(int theIndex)
  {
    checkIndex(theIndex);
    
    copy(element+theIndex+1, element+listSize, element+theIndex);
    /// invoke destructor
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
        changeLength1D(element, arrayLength, 2*arrayLength);
        arrayLength = 2*arrayLength;
      }
    copy_backward(element+theIndex, element+listSize, element+listSize+1);
    element[theIndex] = theElement;
    ++listSize;
  } /// template

  template <typename T>
  void arrayList<T>::output(ostream &out) const
  {
    /// put the list into the stream out.
    /// ostream_iterator属于I/O流STL适配器，用于获取一个元素，同时保存在
    /// 缓冲器中，可以供cout输出，如果把cout看成一个对象，那么cout对象当中
    /// 存在一片用于数据存诸的区域。
    copy(element, element+listSize, ostream_iterator<T>(cout, "  "));
  } /// template

  template <typename T>
  ostream& operator<<(ostream& out, const arrayList<T>& x)
  {
    x.output(out);
    return out;
  } /// template
  
}
#endif /* ARRAYLIST_H */
