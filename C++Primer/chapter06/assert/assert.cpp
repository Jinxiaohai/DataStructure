/**
 * @file   assert.cpp
 * @author xiaohai <xiaohaijin@outlook.com>
 * @date   Wed May 17 21:39:26 2017
 * 
 * @brief  
 * 
 * 
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
#define NDEBUG

using namespace std;


int main(int argc, char *argv[])
{
  double a, b;
  cin >> a >> b;
  assert(a >= b);
  cout << a << "  " << b << endl;
  return 0;
}
