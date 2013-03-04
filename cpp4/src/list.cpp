/*
 * list.cpp
 *
 *  Created on: 2013-02-26
 *      Author: jun
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "list.h"
#include "node.h"

using namespace std;

class ListIterator;

/* List constructor */


/* List destructor */
List::~List()
{
	Node* node = &head_;
	while (node->next() != &head_)
	{
		Node* tmp = node;
		delete tmp;
	}
}

/* add data to the list */
void List::add(int &value)
{
	Iterator* it = createIterator();
	locate(*it,value);
	Node nNode;
	it->current()->addBefore(nNode,value);
}

/* remove data from list */
void List::remove(Iterator & it)
{
	if(it.hasNext())
		it.current()->remove();
}

/* create iterator in list */
Iterator* List::createIterator()
{
	ListIterator* it = new ListIterator(&head_);
	return static_cast<Iterator*>(it);
}

/* get iterator by value*/
Iterator& List::locate(Iterator &it,int value)
{
	while(it.hasNext() )
		if(it.next() == value) break;
	return it;
}

/*
void List::print()
{
	Iterator* it = createIterator();
	while(it->hasNext())
	{
		cout << it->next() << " ";
	}
	cout << it->current()->get();
	delete it;
}
*/
