/*
 * singleLinkedList.h
 *
 *  Created on: 2013-03-07
 *      Author: jun
 */

#ifndef SINGLELINKEDLIST_H_
#define SINGLELINKEDLIST_H_

#include "list.h"

class SingleLinkedList : public List
{
public:
	~SingleLinkedList();
	void add(int &value);
	void remove(int &value);
	Iterator* createIterator();
	void print();

private:
	Node head_;
	void remove(Iterator* it);
};

#endif /* SINGLELINKEDLIST_H_ */
