#ifndef LOWERTRIANGULARMATRIX_H
#define LOWERTRIANGULARMATRIX_H

#include "myExceptions.h"

using namespace std;

template <typename T>
class lowerTriangularMatrix
{
public:
  lowerTriangularMatrix(int theN = 10);
  virtual ~lowerTriangularMatrix()
  {
    delete [] element;
  }
  T get(int, int) const;
  void set(int, int, const T&);
private:
  int n;
  T *element;
}; /// template class

template <typename T>
lowerTriangularMatrix<T>::lowerTriangularMatrix(int theN)
{
  /// constructor
  /// validate theN
  if (theN < 1)
    {
      throw illegalParameterValue("Matrix size must be > 0");
    }
  n = theN;
  /// the size of the array.
  element = new T[n*(n+1)/2];
} ///< template

template <typename T>
T lowerTriangularMatrix<T>::get(int i, int j) const
{
  /// return (i,j)th element of matrix.
  /// validate i and j
  if (i < 1 || j < 1 || i > n || j > n)
    {
      throw matrixIndexOutOfBounds();
    }
  /// (i, j) in lower triangle iff i >= j
  if (i >= j)
    {
      return element[i*(i-1)/2 + j-1];
    }
  else
    {
      return 0;
    }
} ///< template

template <typename T>
void lowerTriangularMatrix<T>::set(int i, int j, const T& newValue)
{
  /// storage newvalue as (i,j)th element.
  /// validate i and j
  if (i < 1 || j < 1 || i > n || j > n)
    {
      throw matrixIndexOutOfBounds();
    }
  /// (i,j) in lower triangle iff i >= j
  if (i >= j)
    {
      element[i*(i-1)/2 + j-1] = newValue;
    }
  else
    {
      if (newValue != 0)
	{
	  throw illegalParameterValue("elements not in lower triangle must be zero");
	}
    }
} ///< template

#endif /* LOWERTRIANGULARMATRIX_H */
