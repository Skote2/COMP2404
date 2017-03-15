#ifndef ProdList_H
#define ProdList_H

#include <string>
#include "Product.h"
#include "defs.h"
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;
/*
	Purpose: Sets up linked listfor products to be used
	add: inserts a product in to the list
	remove: removes product in list
	reorg: shifts in ascending order
	get: returns index to see if it is not out of bounds
	findProd: Goes through array to find matching id product
	getSize: returns size
	toString: takes list and sets up a string
*/
class ProdList
{
	class Node
	{
		friend class ProdList;
		private:
			Product* data;
			Node* next;
			Node* prev;
	};
	
	public:
		ProdList();
		~ProdList();
		void add(Product*);
		void remove(Product*);
		void toString (string&);
		void reOrg();
		int getSize();
		Product* get(int);
		Product* findProd(int);
	private:
		Node* head;

};

#endif

