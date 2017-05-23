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
  auto lambdafunc = [](const string &a, const string &b) -> bool
    {
      return a.size() < b.size();
    };
  string lambda1 = "xiaohai";
  string lambda2 = "xiaopangzi";
  cout << lambdafunc(lambda1, lambda2) << endl;
  return 0;
}
