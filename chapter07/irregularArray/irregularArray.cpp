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

int main(int argc, char *argv[])
{
  int numberOfRows = 5;
  /// define length
  int length[5] = {6, 3, 4, 2, 7};
  int **irregularArray = new int*[numberOfRows];

  for (int i = 0; i != numberOfRows; ++i)
    {
      irregularArray[i] = new int[length[i]];
    }
  
  irregularArray[2][3] = 5;
  irregularArray[4][6] = irregularArray[2][3]+2;
  irregularArray[1][1] = 3;

  cout << irregularArray[2][3] << endl;
  cout << irregularArray[4][6] << endl;
  cout << irregularArray[1][1] << endl;
  return 0;
}
