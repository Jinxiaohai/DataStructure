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
#include <random>
#include "control.h"

using namespace std;

int main(int argc, char *argv[])
{
  Error<string> error;
  Warning<string> warning;
  Prompt<string> prompt;

  prompt(cout) << "G" << prompt.end() << endl;

  return 0;
}
