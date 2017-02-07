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

#ifndef PRODARRAY_H
#define PRODARRAY_H

#include "defs.h"
#include "Product.h"

/*
	Purpose: Sets up array for products to be used
	add: inserts a product in to the array
	get: returns index to see if it is not out of bounds
	findProd: Goes through array to find matching id product
	getSize: returns size
	size: sets up size at 0
	elements: sets up the size of the array for use
*/
class ProdArray
{
  public:
    ProdArray();
    void add(Product&);
    Product& get(int);
    Product& findProd(int);
    int getSize();
  private:
    Product elements[MAX_ARR];
    int size;
};

#endif

