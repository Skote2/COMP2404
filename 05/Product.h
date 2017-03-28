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

#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;
/*
	Purpose: Sets up the product to be used in the program
	getId: returns Id
	getName: returns Name
	getSize: returns Size
	getUnits: returns units
	decrementUnits: decreases stock of units after bought
	getPrice: returns price
	nextProdId: goes to the next id in the array
	id: sets up id of product
	name: set up name of product
	size: sets up size in array
	units: sets up stock of products
	price: sets up price of products
*/
class Product
{
  public:
    Product(string="Unknown", string="Unknown", int=0, float=0.0f);
    int    getId();
    string getName();
    string getSize();
    int    getUnits();
    bool   decrementUnits();
    float  getPrice();
    void   addUnits(int&);
    float  computeTax();
    int  computeExpDate();
    
  protected:
    static int nextProdId;
    int        id;
    string     name;
    string     size;
    int        units;
    float      price;
    Date       ManDate(int y, int m, int d);
    Date       ExpDate();
};

#endif
