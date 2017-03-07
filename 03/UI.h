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

#ifndef UI_H
#define UI_H

#include <string>
using namespace std;

#include "ProdList.h"
#include "ProdArray.h"
#include "CustArray.h"

/*
	Purpose: Interface portion of the program, set up for user choices
	mainMenu: (included by mistake in base code)
	adminMenu: Displays administrative options
	cashierMenu: Displays the customers options
	promptForInt: Reads Int data
	promtForStr: Reads String Data
	printError: Displays Error option
	PrintUsageError: Displays error options for not choosing -a or -c
	printStock: Displays Information on item and quantity
	printCustomers: Displays Data regarding customer
	pause: Displays break in UI
	readInt: Takes str and int values
*/
class UI
{
  public:
    void mainMenu(int&);
    void adminMenu(int&);
    void cashierMenu(int&);
    void promptForInt(string, int&);
    void promptForStr(string, string&);
    void promptForFloat(string, float&);
    void printError(string);
    void printUsageError();
    void printStock(ProdArray*);
    void printStock(ProdList*);
    void printCustomers(CustArray*);
    void pause();

  private:
    int    readInt();
};

#endif
