#ifndef NONPERISHABLE_H
#define NONPERISHABLE_H

#include <string>
using namespace std;

class NonPerishable : public Product
{
 public:
  NonPerishable(string n="") : Product(n) { }
}
#endif
