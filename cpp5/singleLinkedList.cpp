/*
 * singleLinkedList.cpp
 *
 *  Created on: 2013-03-11
 *      Author: jun
 */

#include "singleLinkedList.h"

/* SingleLinkedList destructor */
SingleLinkedList::~SingleLinkedList()
{
	Node* node = &head_;
	while (node->next() != &head_)
	{
		Node* tmp = node;
		node = node->next();
		delete tmp;
	}
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
	if(locate(*it,value).hasNext())
		it->current()->remove();
	delete it;
}

