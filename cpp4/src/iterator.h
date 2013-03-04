/*
 * iterator.h
 *
 *  Created on: 2013-02-26
 *      Author: jun
 */

#ifndef ITERATOR_H_
#define ITERATOR_H_


#include "node.h"
using namespace std;

class Node;

class Iterator
{
public:
	virtual Node* current() = 0;
	virtual int next() = 0;
	virtual bool hasNext() = 0;
	virtual ~Iterator(){};

private:
	// Node* first_;
	 //Node* current_;
};


#endif /* ITERATOR_H_ */
