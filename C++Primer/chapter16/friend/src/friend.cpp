#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstddef>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cassert>

using namespace std;

template <typename T>
class Particle
{
  template <typename U> friend ostream& operator<<(ostream& os, const Particle<U>& p);
public:
  Particle(const T& x, const T& y):xcoor(x), ycoor(y) { }
private:
  T xcoor;
  T ycoor;
}; /// template class

template <typename U>
ostream& operator<<(ostream& s, const Particle<U>& p)
{
  s << p.xcoor << "   " << p.ycoor;
  return s;
} ///< template

int main(int argc, char *argv[])
{
  Particle<int> particle(1, 2);
  cout << particle << endl;
  return 0;
}
