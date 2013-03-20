/*
 * sortDoubleLinkedList.cpp
 *
 *  Created on: 2013-03-19
 *      Author: jun
*/


#include "sortDoubleLinkedList.h"
#include "iterator.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
/* add data to the list */
void SortDoubleLinkedList::add(int &value)
{
	Iterator *it = createIterator();
	CircleNode *nNode = new CircleNode();
	dynamic_cast<CircleNode*>(locate(*it,value).current())->addBefore(*nNode,value);
	delete it;
}

/* remove data from list */
void SortDoubleLinkedList::remove(int &value)
{
	Iterator* it = createIterator();
	DoubleLinkedList::locate(*it,value);
	if ((it->current()->get() == value) && (it->current() != &head_)) {
			it->current()->remove();
			delete it->current();
	} else {
		cout << "Sorry, there is no integer " << value << " in the list" << endl;
	}
	delete it;
}

/* get iterator by value*/
Iterator& SortDoubleLinkedList::locate(Iterator &it,int value)
{
	while(it.hasNext())
		if (it.next() > value) break;
	return it;
}
