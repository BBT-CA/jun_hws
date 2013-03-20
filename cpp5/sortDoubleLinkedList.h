/*
 * sortDoubleLinkedList.h
 *
 *  Created on: 2013-03-07
 *      Author: jun
 */

#ifndef SORTDOUBLELINKEDLIST_H_
#define SORTDOUBLELINKEDLIST_H_

#include "doubleLinkedList.h"

class SortDoubleLinkedList : public DoubleLinkedList
{
public:
	void add(int &value);
	void remove(int &value);
private:
	CircleNode head_;
	virtual Iterator& locate(Iterator& it, int value);

};

#endif /* SORTDOUBLELINKEDLIST_H_ */
