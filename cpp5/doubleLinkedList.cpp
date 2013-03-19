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

using namespace std;
/* DobleLinkedList destructor */
DoubleLinkedList::~DoubleLinkedList()
{
	CircleNode* node = head_.next();
	while (node->next() != &head_)
	{
		CircleNode* tmp = node;
		node->remove();
		node = tmp->next();
		delete tmp;
	}
}

/* add data to the list */
void DoubleLinkedList::add(int &value)
{
	Iterator *it = createIterator();
	CircleNode *nNode = new CircleNode();
	dynamic_cast<CircleNode*>(it->current())->addAfter(*nNode,value);
	delete it;
}

/* remove data from list */
void DoubleLinkedList::remove(int &value)
{
	Iterator* it = createIterator();
	if (locate(*it,value).current()->get() == value) {
		if(locate(*it,value).current() != &head_) {
			it->current()->remove();
			delete it->current();
		}
	} else {
		cout << "Sorry, there is no integer " << value << " in the list" << endl;
	}
	delete it;
}

/* create iterator */
Iterator* DoubleLinkedList::createIterator()
{
	return new ListIterator(&head_);
}

void DoubleLinkedList::print()
{
	Iterator* it = createIterator();
	while(it->hasNext())
	{
		cout <<it->next() << " " ;
	}
	cout << endl;
	delete it;
}


