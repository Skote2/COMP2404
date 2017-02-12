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

#ifndef CUSTARRAY_H
#define CUSTARRAY_H

#include "defs.h"
#include "Customer.h"
/*
	Purpose:Takes customers and places in Array
	CustArray: Initalizes size
	add: Inserts customer
	get: Checks space and exit if full if not returns customers 
	getSize: returns size
*/
class CustArray
{
  public:
    CustArray();
    void add(Customer*);
    Customer* get(int);
    int getSize();
  private:
    Customer* elements[MAX_ARR];
    int size;
};

#endif

