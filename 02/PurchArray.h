#ifndef PURCHARRAY_H
#define PURCHARRAY_H

#include "defs.h"
#include "Purchase.h"

/*
	Purpose: Sets up array for purchases done by customer
	get: returns the index
	getSize: returns the size of array
	getNumPurchases: returns the amount of purchases of product
	newPurchase: Sets up a purchases checks to see if it is valid
	pArr: array of purchases set up with index
	totalPurchases: all purchases
	arrSize: set to zero grows as purchases are added


*/
class PurchArray
{
  public:
    PurchArray();
    ~PurchArray();
    Purchase& get(int);
    int getSize();
    int getNumPurchases();
    int getNumPurchases(int);
    void newPurchase(int);
  private:
    Purchase* pArr[MAX_ARR];
    int totalPurchases;
    int arrSize;
};

#endif

