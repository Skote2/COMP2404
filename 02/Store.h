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

#ifndef STORE_H
#define STORE_H

#include "ProdArray.h"
#include "Product.h"
#include "CustArray.h"
#include "Customer.h"
#include <iostream>

/*
	Purpose: Sets up store for customers with products
	addProd: adds Product to store
	addCust: adds Customer to store
	purchaseProduct: finds product and sets up points for it
	getProduct: returns product
	getCustomer: returns customer
	getStock: returns Stock of product
	getCustomers: returns Customers 
	stock: sets up quantity of product
	customers: sets up customer for store usage 
*/

class Store
{
  public:
    void       addProd(Product&);
    void       addCust(Customer&);
    void       purchaseProduct(Customer*, int[]);
    Product&   getProduct(int&);
    Customer&  getCustomer(int&);
    ProdArray& getStock();
    CustArray& getCustomers();
  private:
    ProdArray  stock;
    CustArray  customers;
};

#endif
