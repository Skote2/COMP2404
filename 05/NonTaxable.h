#ifndef NONTAXABLE_H
#define NONTAXABLE_H

#include <string>
using namespace std;

class NonTaxable : public Product
{
 public:
  NonTaxable(string n="") : Product(n) { }
}
#endif
