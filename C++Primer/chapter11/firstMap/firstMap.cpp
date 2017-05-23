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
  map<string, size_t> word_count;
  string word;
  while (cin >> word)
    {
      ++word_count[word];
    }
  for (const auto &w : word_count)
    {
      cout << w.first << " occurs " << w.second << endl;
    }
  return 0;
}
