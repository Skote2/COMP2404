#include "PurchArray.h"

PurchArray::PurchArray()
{
    totalPurchases = 0;
    arrSize = 0;
}
PurchArray::~PurchArray()
{
    for(int i = 0; i < arrSize; i++)
        delete pArr[i];
}
Purchase& PurchArray::get(int index) { return (*pArr[index]); }
int PurchArray::getSize() { return arrSize; }
int PurchArray::getNumPurchases()
{return totalPurchases;}

int PurchArray::getNumPurchases(int prodID)
{
    for (int i = 0; i < arrSize; i++)
        if ((*pArr[i]).getProductId() == prodID)
            return (*pArr[i]).getTimesPurchased();
    return 0;
}

void PurchArray::newPurchase(int prodID)
{
    int arrID = 0;
    for (; arrID < arrSize; arrID++)
        if ((*pArr[arrID]).getProductId() == prodID)
            break;

    if (arrID == arrSize)
    {
        pArr[arrID] = new Purchase(prodID);
        arrSize++;
    }
    else
        (*pArr[arrID]).newPurchase();
    totalPurchases++;
}
