#include <iostream>
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
	newProdNode->data = stu;
	newProdNode->next = NULL;
	
	currNode = head;
	prevNode = NULL;
	
	while (currNode != NULL) 
	{
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
	delete currNode;
}
/*
void ProdList::reOrg()
{
	What the fuck do I do here?
	I have to sort the list in ascending order of units
	but what kind of sort is nice and fast for this?
	She said a bubble sort or another algorithm is fine but
	I'm shit at doing that since my 1405 skills are ass
}

*/