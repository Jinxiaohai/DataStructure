#ifndef DIALOGMATRIX_H
#define DIALOGMATRIX_H

#include "myExceptions.h"

using namespace std;

template <typename T>
class diagonalMatrix
{
public:
  diagonalMatrix(int theN = 10);
  virtual ~diagonalMatrix()
  {
    delete [] element;
  }
  T get(int, int) const;
  void set(int, int, const T&);
private:
  /// 1 Dimension array
  int n;
  T *element;
}; /// template class

template <typename T>
diagonalMatrix<T>::diagonalMatrix(int theN)
{
  /// constructor
  /// validate theN
  if (theN < 1)
    {
      throw illegalParameterValue("Matrix size must be > 0");
    }
  n = theN;
  element = new T[n];
} ///< template

template <typename T>
T diagonalMatrix<T>::get(int i, int j) const
{
  /// return (i,j)th element of matrix
  /// validate i and j
  if (i < 1 || j < 1 || i > n || j > n)
    {
      throw matrixIndexOutOfBounds();
    }
  if (i == j)
    {
      return element[i-1];
    }
  else
    {
      return 0;
    }
} ///< template

template <typename T>
void diagonalMatrix<T>::set(int i, int j, const T& newValue)
{
  /// store newValue as (i,j)th element
  /// validate i and j
  if (i < 1 || j < 1 || i > n || j > n)
    {
      throw matrixIndexOutOfBounds();
    }
  if (i == j)
    {
      /// save the dialog value
      element[i-1] = newValue;
    }
  else
    {
      if (newValue != 0)
	{
	  throw illegalParameterValue("nondiagonal elements must be zero");
	}
    }
} ///< template

#endif /* DIALOGMATRIX_H */
