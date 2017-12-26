#ifndef BOOSTER_H
#define BOOSTER_H

#include <iostream>

struct booster
{
  int degradeToLeaf;
  int degradeFromParent;
  bool boosterHere;

  void output(ostream& out) const
  {
    out << boosterHere << "   " << degradeToLeaf << "   "
        << degradeFromParent << "  ";
  }

};
ostream& operator<<(ostream& out, booster x)
{
  x.output(out);
  return out;
}


#endif /* BOOSTER_H */
