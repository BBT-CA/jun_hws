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
	dynamic_cast<CircleNode*>(locAddPosition(*it,value).current())->addBefore(*nNode,value);
	delete it;
}

/* get iterator by value*/
Iterator& SortDoubleLinkedList::locAddPosition(Iterator &it,int value)
{
	while(it.hasNext())
		if (it.next() > value) break;
	return it;
}
