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
private:
	virtual Iterator& locAddPosition(Iterator& it, int value);

};

#endif /* SORTDOUBLELINKEDLIST_H_ */
