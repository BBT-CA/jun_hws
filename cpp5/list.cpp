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
	current_ = current_->next();
	return current_->get();
}

bool List::ListIterator::hasNext()
{
	return (current_->next() != iHead_);
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
/*
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
*/
