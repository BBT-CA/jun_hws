/*
 * doubleLinkedList.h
 *
 *  Created on: 2013-03-07
 *      Author: jun
 */

#ifndef DOUBLELINKEDLIST_H_
#define DOUBLELINKEDLIST_H_

#include "list.h"
#include "circleNode.h"

class DoubleLinkedList : public List
{
public:
	virtual ~DoubleLinkedList();
	virtual void add(int &value);
	void remove(int &value);
	Iterator* createIterator();
	void print();

private:
	CircleNode head_;
};

#endif /* DOUBLELINKEDLIST_H_ */
