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

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "Store.h"

Product* Store::getProduct(int& prodId)
{
  for (int i = 0; i < stock.getSize(); i++)
    if (stock.get(i)->getId() == prodId)
      return stock.get(i);
      //Ids star at 5065
  std::cout << "Error: Product not found" << endl;
  exit(1);
}
Customer* Store::getCustomer(int& custId)
{
  for (int i = 0; i < customers.getSize(); i++)
    if (customers.get(i)->getId() == custId)
      return customers.get(i);
      //Ids start at 2065
  std::cout << "Error Customer not found" << std::cout;
  exit(1);
}

ProdList* Store::getStock()     { return &stock; }
CustArray* Store::getCustomers() { return &customers; }

void Store::addProd(Product* prod)
{
  stock.add(prod);
}

void Store::addCust(Customer* cust)
{
  customers.add(cust);
}

void Store::purchaseProduct(Customer *cust, int prodIds[])
{
  int points = (*cust).getPoints();
  float cost = 0;
  //Product& prod = stock.findProd((*prods).get(0).getId());
  std::cout << "\n            Thankyou\n           Come again\n--------------------------------" << std::endl;
  for(int i = 0; prodIds[i] != 0; i++)
  {
    Product* prod = stock.findProd(prodIds[i]);
    if (prod->decrementUnits())
    {
      (*cust).madePurchase(prod);
      cost += prod->getPrice();
      std::cout << setw(5) << prod->getId() << " " << setw(20) << prod->getName() << setw(6) << prod->getPrice() << endl;
    }
    else
    {
      std::cout << "Error: Out of stock of " << prod->getName() << std::endl;
      exit(1);
    }
  }
  std::cout << "\nPoints Earned: " << ((*cust).getPoints() - points) << std::endl;
  std::cout << "Your total: $" << cost << std::endl;
}
