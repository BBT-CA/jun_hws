/*
 * doubleLinkedList.cpp
 *
 *  Created on: 2013-03-11
 *      Author: jun
 */

#include "doubleLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <typeinfo>
using namespace std;
/* DobleLinkedList destructor */
DoubleLinkedList::~DoubleLinkedList()
{
	CircleNode* node = &head_;
	while (node->next() != &head_)
	{
		CircleNode* tmp = node;
		node->remove();
		delete tmp;
	}
}

/* add data to the list */
void DoubleLinkedList::add(int &value)
{
	Iterator *it = createIterator();
	CircleNode *nNode = new CircleNode();
	dynamic_cast<CircleNode*>(it->current())->addAfter(*nNode,value);
}

/* remove data from list */
void DoubleLinkedList::remove(int &value)
{
	Iterator* it = createIterator();
	if(locate(*it,value).hasNext())
		it->current()->remove();
	delete it;
}

/* create iterator */
Iterator* DoubleLinkedList::createIterator()
{
	return new ListIterator(&head_);
}

void DoubleLinkedList::print()
{
	Iterator* it = new ListIterator(&head_);
	cout << "type of it:" << typeid(it).name();
	while(it->hasNext())
	{cout << "hello" << endl;
		cout <<it->next() << " " ;
	}
	cout << "double print" << endl;
	delete it;
}
