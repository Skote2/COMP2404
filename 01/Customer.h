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

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

#include "Product.h"
#include "PurchArray.h"

/*
	Purpose: Sets up Customer Data to be filled
	getId: return id of customer
	getName: return name of customer
	getPoints: return the points of customer
	madePurchase: takes purchase and converts to points and adds to history
	printPurchHistory: displays the purchase history of customer
	purchHistory: Array of items purchased
	nextCustId: next customer
	id: initializes id of customer
	name: initializes name of customer
	points: initializes points of customer

*/
class Customer
{
  public:
    ~Customer();
    Customer(string="Unknown");
    int    getId();
    string getName();
    int    getPoints();
    void   madePurchase(Product*);
    void   printPurchHistory();
  protected:
    PurchArray purchHistory;
    static int nextCustId;
    int        id;
    string     name;
    int        points;
};

#endif
