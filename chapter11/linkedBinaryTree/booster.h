#ifndef BOOSTER_H
#define BOOSTER_H

#include <iostream>
using namespace std;

struct booster
{
  /// 落叶
  int degradeToLeaf;
  int degradeToParent;
  bool boosterHere;

  void output(ostream& out) const
  {
    out << boosterHere << "  " << degradeToLeaf << "  " << degradeToParent << "  ";
  }
};

ostream& operator<<(ostream& out, booster x)
{
  x.output(out);
  return out;
}


#endif /* BOOSTER_H */
