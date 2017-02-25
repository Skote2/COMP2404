/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/*  Program:  Simple Inventory System              */
/*  Author:   Christine Laurendeau                 */
/*  Date:     28-JUN-2016                          */
/*                                                 */
/*  (c) 2016 Christine Laurendeau                  */
/*  All rights reserved.  Distribution and         */
/*  reposting, in part or in whole, without the    */
/*  written consent of the author, is illegal.     */
/*                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <iomanip>
#include <math.h>
#include "Customer.h"

int Customer::nextCustId = 2001;

Customer::~Customer(){}

Customer::Customer(string n)
{ 
  purchHistory = PurchArray();
  id     = nextCustId++;
  name   = n;
  points = 0;
}

int    Customer::getId()     { return id;     }
string Customer::getName()   { return name;   }
int    Customer::getPoints() { return points; }

void Customer::madePurchase(Product *prod)
{
  points += round(prod->getPrice());
  purchHistory.newPurchase(prod->getId());
}

void Customer::printPurchHistory ()
{
  Purchase* purch;

  std::cout << setw(6) << "Id " << setw(7) << "#buys" << std::endl;
  for (int i = 0; i < purchHistory.getSize(); i++)
  {
    purch = purchHistory.get(i);
    std::cout << setw(6) << purch->getProductId() << setw(7) << purch->getTimesPurchased() << std::endl;
  }
  std::cout << "Total Buys: " << purchHistory.getNumPurchases() << endl;
}
