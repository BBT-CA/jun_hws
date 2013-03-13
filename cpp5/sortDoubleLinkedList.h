/*
 * sortDoubleLinkedList.h
 *
 *  Created on: 2013-03-07
 *      Author: jun
 */

#ifndef SORTDOUBLELINKEDLIST_H_
#define SORTDOUBLELINKEDLIST_H_

#include "list.h"
/*
 * way1: copy to array then sort  //only for nodes less than 10 thousand.
 * way2: locate(); maintain a binary tree (red-black tree, virtual). data store in list.
 */
class SortList : public List
{
public:


protected:
	virtual Iterator& locate(Iterator& it, int value);
private:
	Node head_;
};


/* question: how to write constructor and destructor if they are the same as parent's */
/* answer: don't write constructor in child class. It will go to parent's constructor automatically */



#endif /* SORTDOUBLELINKEDLIST_H_ */
