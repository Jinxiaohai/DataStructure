#ifndef MATRIXTERM_H
#define MATRIXTERM_H

using namespace std;

template <typename T>
struct matrixTerm
{
  int row;
  int col;
  T value;
  /// type conversion from matrixterm to T
  operator T() const
  {
    return value;
  }
};

#endif /* MATRIXTERM_H */
