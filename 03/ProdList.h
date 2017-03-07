#ifndef ProdList_H
#define ProdList_H

#include <string>
#include "Product.h"
#include "defs.h"
// This linkedlist is basically me watching the lecture and trying To understand it
// Christine said a finding function will be useful
// Need to make sure on memory leaks
// Printing shouldn't be done here like christine did in her examples but in UI

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
		void reOrg();
		int getSize();
		Product* get(int);
		Product* findProd(int);
	private:
		Node* head;

};

#endif
