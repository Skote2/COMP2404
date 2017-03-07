#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

#include "ProdList.h"

ProdList::ProdList() : head(0) { }

ProdList::~ProdList()
{
	Node* currNode = head;
	Node* nextNode;
	
	while(currNode != NULL) 
	{
		nextNode = currNode->next;
		delete currNode->data;
		delete currNode;
		currNode = nextNode;
	}
}

void ProdList::add(Product* prod)
{
	Node* newProdNode;
	Node* currNode;
	Node* prevNode;
	
	
	newProdNode = new Node;
	newProdNode->data = prod;
	newProdNode->next = NULL;
	newProdNode->prev = NULL;
	currNode = head;
	prevNode = NULL;
	
	while (currNode != NULL) 
	{
		//Should be adding in ascending order
		if (newProdNode->data->getUnits() < currNode->data->getUnits())
		{
			break;
		}
		prevNode = currNode;
		currNode = currNode->next;
	}
	// Add to first part
	if (prevNode == NULL) 
	{
		head = newProdNode;
	}
	else
	{
		prevNode->next = newProdNode;
	}
	newProdNode->next = currNode;
	newProdNode->prev = prevNode;
	if (currNode != NULL)
	{
		currNode->prev = newProdNode;
	}
}

void ProdList::remove(Product* prod)
{
	Node* currNode = head;
	Node* prevNode = NULL;
	
	while (currNode != NULL)
	{
		if (currNode->data->getName() == prod->getName())
			break;
		prevNode = currNode;
		currNode = currNode->next;
			
	}
	
	if (prevNode == NULL)
	{
		head = currNode->next;
	}
	else
	{
		prevNode->next = currNode->next;
	}
	delete currNode->data;
	delete currNode;
}

void ProdList::reOrg()
{
	Node* currNode = head;
	Node* prevNode = NULL;

	//int size = 0;
	for(currNode != NULL; prevNode = currNode; currNode = currNode->next)
	{
		if(currNode->data->getUnits() < prevNode->data->getUnits())
		{
			if(currNode->prev != NULL)
			{
				prevNode->prev->next = currNode;
			}
			if(currNode->next != NULL)
			{
				currNode->next->prev = prevNode;
			}
			
			currNode->prev = prevNode->prev;
			prevNode->next = currNode->next;
			currNode->next = prevNode;
			prevNode->prev = currNode; 
			if(head == prevNode)
			{
				head = currNode;
			}
			if(prevNode->next = NULL)
			{
				break;
			}
		}
	}
}

int ProdList::getSize()
{
	int c = 0;
	Node* curr = head;
	while (curr != 0)
	{
		curr = curr->next;
		c++;
	}
	return c;
}
Product* ProdList::get(int i)
{
	int c = 0;
	Node* curr = head;
	while (curr != 0 && c < i)
	{
		curr = curr->next;
		c++;
	}
	return curr->data;
}
Product* ProdList::findProd(int id)
{
	Node* curr = head;
	while (curr != 0)
	{
		if (curr->data->getId() == id)
			return curr->data;
		else
			curr = curr->next;
	}
	return 0;
}

void ProdList::toString (string& outStr)
{
	stringstream ss;
	outStr += "STOCK: \n\n";
  	outStr += " ID                                 Name             Size    Qty    Price\n";
  	outStr += " --                                 ----             ----    ---    -----\n";
	for (int i=0; i< getSize(); i++) 
	{
		Product* prod = get(i);

		ss << prod->getId()   << "  " << setw(40) << prod->getName() << "  "
			<< setw(10) << prod->getSize() << "  " << setw(4)  << prod->getUnits() << "    ";

		ss << "$" << setw(6) << fixed << setprecision(2) << prod->getPrice() << endl;

		//ss.str("");
	}
		outStr += ss.str();
}