#ifndef PURCHASE_H
#define PURCHASE_H


/*
	Purpose: Sets up product purchasing feature
	newPurchase: sets up a new purchase
	getTimesPurchased: returns times Purchased
	getProductId: returns product id
	productId: sets up product with an id
	timesPurchased: if not new purchase sets up so it can be accounted for
*/
class Purchase
{
	public:
		Purchase();
		Purchase(int);
		void newPurchase();
		int getTimesPurchased();
		int getProductId();
	private:
		int productId;
		int timesPurchased;
};

#endif
