#ifndef ORDERARRAY_H
#define ORDERARRAY_H

#include "defs.h"
#include "Order.h"

class OrderArray
{
	public:
	 OrderArray();
	 ~OrderArray();
	 Order* get(int);
	 int getSize();
	 int getNumOrders();
	private:
	 Order* oArr[MAX_ARR];
	 int arrSize;
	 int totalOrders;
};

#endif
