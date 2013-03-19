/*
 * singleLinkedList.cpp
 *
 *  Created on: 2013-03-11
 *      Author: jun
 */

#include "singleLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>

using namespace std;

/* SingleLinkedList destructor */
SingleLinkedList::~SingleLinkedList()
{
	Node* node = head_.next();
	while (node->next() != &head_)
	{
		Node* tmp = node;
		node = node->next();
		delete tmp;
	}
	delete node;
}

void SingleLinkedList::add(int &value)
{
	Iterator *it = createIterator();
	Node *nNode = new Node();
	it->current()->addAfter(*nNode,value);
	delete it;
}

void SingleLinkedList::remove(int &value)
{
	Iterator* it = createIterator();
	if (locate(*it,value).current()->get() == value) {
		if(it->hasNext()) {
			Node* tmp = it->current()->next();
			it->current()->remove();
			delete tmp;
		} else {
			remove(it);
		}
	} else {
		cout << "Sorry, there is no integer " << value << " in the list" << endl;
	}
	delete it;
}

void SingleLinkedList::remove(Iterator* it)
{
	Iterator* itL = createIterator();
	while(itL->current()->next() != it->current()) {
		itL->next();
	}
	itL->current()->remove(&head_);
	delete it->current();
	delete itL;
}

/* create iterator */
Iterator* SingleLinkedList::createIterator()
{
	return new ListIterator(&head_);
}

void SingleLinkedList::print()
{
	Iterator* it = createIterator();
	while(it->hasNext())
	{
		cout << it->next() << " " ;
	}
	cout << endl;
	delete it;
}

