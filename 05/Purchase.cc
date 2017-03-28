#include "Purchase.h"

Purchase::Purchase(){}
Purchase::Purchase(int pId)
: productId(pId), timesPurchased(1)
{}

int Purchase::getTimesPurchased()   { return timesPurchased; }
int Purchase::getProductId()        {return productId;}

void Purchase::newPurchase()        { timesPurchased++;}
