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

#ifndef INVCONTROL_H
#define INVCONTROL_H

#include "Store.h"
#include "UI.h"

/*
	Purpose: Sets up processes needed for the menu and creates data of products and customers
	launch: Takes menu options from user and sends to the proper response
	store: allows alterations for Store
	view: presents the user interface and allows alterations
	initProducts: initializes Products
	initcustomers: initializes Customers
	processAdmin: creates admin Menu environment
	processCashier: creates Cashier menu environment
*/
class InvControl
{
  public:
    InvControl();
//    ~InvControl();
    void launch(int, char*[]);
  private:
    Store     store;
    UI        view;
    void      initProducts();
    void      initCustomers();
    void      processAdmin();
    void      processCashier();
};
#endif
