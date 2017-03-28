#ifndef PERISHABLE_H
#define PERISHABLE_H

#include <string>
using namespace std;

//Idk if this is what they want for derived
class Perishable : public Product
{
 public:
  Perishable(string n="") : Product(n) { }
  int lifespan;
}
