#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstddef>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cassert>

using namespace std;

int main(int argc, char *argv[])
{
  char *inputdata = "/home/xiaohai/Github/DataStructure/C++Primer/chapter08/input/input.dat";
  ifstream input(inputdata, ifstream::in);
  if (!input.good())
    {
      cerr << "open error." << endl;
      return -1;
    }
  ofstream output1("/home/xiaohai/Github/DataStructure/C++Primer/chapter08/output/output1.dat",
		   ofstream::out | ofstream::trunc);

  unsigned int number = 0;
  while (input.good())
    {
      input >> number;
      ofstream output2("/home/xiaohai/Github/DataStructure/C++Primer/chapter08/output/output2.dat",
		       ofstream::out | ofstream::app);
      output1 << number;
      output2 << number;
      output2.close();
    }
  output1.close();
  return 0;
}
