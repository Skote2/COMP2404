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
#include <iomanip>
#include "InvControl.h"
#include "Store.h"

InvControl::InvControl()
{
  initProducts();
  initCustomers();
}
/* InvControl::~InvControl()
{

}
*/
void InvControl::launch(int argc, char* argv[])
{
  if (argc != 2) {
    view.printUsageError();
    exit(1);
  }

  string option(argv[1]);

  if (option == "-a") {		// Admin menu
    processAdmin();
  }
  else if (option == "-c") {	// Cashier menu
    processCashier();
  }
  else {
    view.printUsageError();
    exit(1);
  }
}

void InvControl::processAdmin()
{
  int    choice;
  string prodName, prodSize;
  int    newUnits, prodUnits, prodId, amount;
  float  prodPrice;

  while (1) {
    choice = -1;
    view.adminMenu(choice);
    if (choice == 1) {		// add new product
      view.promptForStr("Product name", prodName);
      view.promptForStr("Product size", prodSize);
      view.promptForInt("# units", prodUnits);
      view.promptForFloat("Price", prodPrice);
      Product* prod = new Product(prodName, prodSize, prodUnits, prodPrice);
      store.addProd(prod);
      view.pause();
    }
    else if (choice == 2) {
	// add inventory
	view.promptForInt("Enter product ID: ", prodId);
	Product* prod = store.getProduct(prodId);
	view.promptForInt("Enter amount of units: ", newUnits);
	if (newUnits < 0) {
		view.printError("Amount of units entered is too low ");
	}
	else {
		prod->addUnits(newUnits);
		
	}		
    }
    else if (choice == 3) {	// print inventory
      view.printStock(store.getStock());
      view.pause();
    }
    else if (choice == 4) {	// print customers
      view.printCustomers(store.getCustomers());
      view.pause();
    }
    else if (choice == 5) {
      view.promptForInt("Enter product ID: ", prodId);
      if (store.getProduct(prodId) != NULL) {
       Product* prod = store.getProduct(prodId);
	store.getStock()->remove(prod);
      }
      else {
       view.printError("ID not found");
      }
    }
    else {
      break;
    }
  }
}

void InvControl::processCashier()
{
  int choice;
  int custId, numIds = 0;
  int prodIds[MAX_ARR];

  while (1) {
    choice = -1;
    view.cashierMenu(choice);
    if (choice == 1) {			// purchases
      view.promptForInt("What is your cutomer Id ", custId);
      Customer* cust = store.getCustomer(custId);
      while(numIds != 0) {
      view.promptForInt("Enter Ids of items you wish to buy, ending with zero ", prodIds[numIds]);
      numIds++;
      }
      if (prodIds[numIds-1] != 0)
      {
        while (1)
        { // Collects List of Products to be purchased
          if (numIds == MAX_ARR - 1)
          {
            prodIds[numIds] = 0;
            break;
          }
          view.promptForInt("Enter Next Id or 0 to end ", prodIds[numIds]);
          numIds++;
          if (prodIds[numIds-1] == 0)
            break;
        }
        store.purchaseProduct(cust, prodIds);
      }
	}
    
    else if (choice == 2) {		// return purchases
      view.printError("Feature not implemented");
    }
    else if (choice == MAGIC_NUM) {	// print inventory and customers
      view.printStock(store.getStock());
      view.printCustomers(store.getCustomers());
      view.pause();
    }
	
    else {
      break;
    }
  }
}

void InvControl::initProducts()
{

  Product* prod01 = new Product("Sudzzy Dish Soap", "1 L", 10, 3.99f);
  store.addProd(prod01);

  Product* prod02 = new Product("Peachy Laundry Soap", "2 L", 3, 8.99f);
  store.addProd(prod02);

  Product* prod03 = new Product("Daisy's Spicy Chili", "150 g", 5, 1.29f);
  store.addProd(prod03);

  Product* prod04 = new Product("Daisy's Maple Baked Beans", "220 g", 2, 2.49f);
  store.addProd(prod04);

  Product* prod05 = new Product("Marmaduke Hot Dogs", "12-pack", 4, 4.99f);
  store.addProd(prod05);

  Product* prod06 = new Product("Garfield Hamburger Patties", "900 g", 2, 11.99f);
  store.addProd(prod06);

  Product* prod07 = new Product("Chunky Munkey Ice Cream", "2 L", 1, 2.97f);
  store.addProd(prod07);

  Product* prod08 = new Product("It's Your Bday Chocolate Cake", "500 g", 0, 12.99f);
  store.addProd(prod08);

  Product* prod09 = new Product("Happy Baker's Hot dog buns", "12-pack", 5, 3.49f);
  store.addProd(prod09);

  Product* prod10 = new Product("Happy Baker's Hamburger buns", "8-pack", 8, 3.99f);
  store.addProd(prod10);

  Product* prod11 = new Product("Moo-cow 2% milk", "1 L", 7, 2.99f);
  store.addProd(prod11);

  Product* prod12 = new Product("Moo-cow 2% milk", "4 L", 3, 4.99f);
  store.addProd(prod12);

  Product* prod13 = new Product("Moo-cow 5% coffee cream", "250 ml", 4, 1.49f);
  store.addProd(prod13);

  Product* prod14 = new Product("Good Morning Granola Cereal", "400 g", 2, 5.49f);
  store.addProd(prod14);

  Product* prod15 = new Product("Lightening Bolt Instant Coffee", "150 g", 8, 4.99f);
  store.addProd(prod15);

  Product* prod16 = new Product("Lightening Bolt Decaf Coffee", "100 g", 2, 4.99f);
  store.addProd(prod16);

  Product* prod17 = new Product("Munchies BBQ Chips", "250 g", 7, 2.99f);
  store.addProd(prod17);

  Product* prod18 = new Product("Munchies Ketchup Chips", "250 g", 3, 2.99f);
  store.addProd(prod18);

  Product* prod19 = new Product("Dogbert Salted Chips", "210 g", 4, 1.99f);
  store.addProd(prod19);

  Product* prod20 = new Product("Dogbert Sweet and Spicy Popcorn", "180 g", 5, 2.29f);
  store.addProd(prod20);

}

void InvControl::initCustomers()
{
  Customer* cust01 = new Customer("Starbuck");
  Customer* cust02 = new Customer("Apollo");
  Customer* cust03 = new Customer("Boomer");
  Customer* cust04 = new Customer("Athena");
  Customer* cust05 = new Customer("Helo");
  Customer* cust06 = new Customer("Crashdown");
  Customer* cust07 = new Customer("Hotdog");
  Customer* cust08 = new Customer("Kat");
  Customer* cust09 = new Customer("Chuckles");
  Customer* cust10 = new Customer("Racetrack");

  store.addCust(cust01);
  store.addCust(cust02);
  store.addCust(cust03);
  store.addCust(cust04);
  store.addCust(cust05);
  store.addCust(cust06);
  store.addCust(cust07);
  store.addCust(cust08);
  store.addCust(cust09);
  store.addCust(cust10);
}

