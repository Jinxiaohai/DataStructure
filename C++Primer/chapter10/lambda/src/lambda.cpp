/**
 * @file   lambda.cpp
 * @author xiaohai <xiaohaijin@outlook.com>
 * @date   Mon May 22 21:16:18 2017
 * 
 * @brief  lambda expression.
 */

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
  int f = []() -> {return 42;};
  cout << f() << endl;
  return 0;
}
