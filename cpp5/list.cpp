/*
 * list.cpp
 *
 *  Created on: 2013-03-05
 *      Author: jun
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "list.h"
#include "node.h"

using namespace std;

/* ListIterator */
List::ListIterator::ListIterator(Node* node)
{
	iHead_ = node;
	current_ = node;
}

Node* List::ListIterator::current()
{
	return current_;
}

int List::ListIterator::next()
{
	Node* tmp = current_->next();
	current_ =  tmp;
	return current_->get();
}

bool List::ListIterator::hasNext()
{
	return (current_->next() != iHead_);
}


/* List destructor */
/*
List::~List()
{
	Node* node = &head_;
	while (node->next() != &head_)
	{
		Node* tmp = node;
		node = node->next();
		delete tmp;
	}
}
*/
/* add data to the list */
/*
void List::add(int &value)
{
	Iterator *it = createIterator();
	locate(*it,value);
	Node *nNode = new Node();
	it->current()->addAfter(*nNode,value);
	delete it;
}
*/
/* remove data from list */
/*
void List::remove(int &value)
{
	Iterator* it = createIterator();
	if(locate(*it,value).hasNext())
		it->current()->remove();
	delete it;
}
*/
/* create iterator */
Iterator* List::createIterator()
{
//	ListIterator* it = new ListIterator(&head_);
//	return dynamic_cast<Iterator *>(it);
	return new ListIterator(&head_);
}

/* get iterator by value*/
Iterator& List::locate(Iterator &it,int value)
{
	while(it.hasNext()){
	if(it.next() == value)
			break;
	}
	return it;
}

void List::print()
{
	Iterator* it = createIterator();
	while(it->hasNext())
	{
		cout << it->next() << " " ;
	}
	cout << endl;
	delete it;
}

