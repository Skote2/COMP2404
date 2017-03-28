#ifndef TAXABLE_H
#define TAXABLE_H

#include <string>
using namespace std;

class Taxable : public Product
{
 public:
  Taxable(string n="") : Product(n) { }
}
#endif
