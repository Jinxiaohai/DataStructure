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
  string hello = "xiaopangzi";
  ostringstream outputdata;
  outputdata << hello;
  cout << outputdata.str() << endl;
  return 0;
}
