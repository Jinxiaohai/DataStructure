/**
 * @file   istringstream.cpp
 * @author xiaohai <xiaohaijin@outlook.com>
 * @date   Mon May 22 19:58:40 2017
 * 
 * @brief  istringstream test.
 */
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;
int main(int argc, char *argv[])
{
  ifstream input("/home/xiaohai/Github/DataStructure/C++Primer/chapter08/ostream/input/test.dat");
  if (input.fail())
    {
      cerr << "open error." << endl;
      return -1;
    }
  string line;
  getline(input, line);
  istringstream inputdata(line);
  string data1, data2;
  inputdata >> data1 >> data2;
  cout << data1 << data2 << endl;
  return 0;
}
