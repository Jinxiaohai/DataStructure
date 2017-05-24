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
bool compare(const T& a, const T& b)
{
  if (a > b)
    {
      return true;
    }
  else
    {
      return false;
    }
} ///< template

int main(int argc, char *argv[])
{
  cout << compare(12, 13) << endl;
  cout << compare(13, 12) << endl;
  return 0;
}
