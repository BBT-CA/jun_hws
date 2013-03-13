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
	virtual ~SingleLinkedList();
	void add(int &value);
	void remove(int &value);

private:
	Node head_;


};

#endif /* SINGLELINKEDLIST_H_ */
