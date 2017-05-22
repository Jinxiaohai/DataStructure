/**
 * @file   hello.cpp
 * @author xiaohai <xiaohaijin@outlook.com>
 * @date   Wed May 17 22:07:49 2017
 * 
 * @brief  g++ -fpic -shared hello.cpp -o libhello.so 
 * 
 */
#include <iostream>
#include "hello.h"
using namespace std;

void shuchu()
{
  cout << "Hello world." << endl;
}
