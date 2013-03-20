/*
 * iterator.h
 *
 *  Created on: 2013-03-05
 *      Author: jun
 */

#ifndef ITERATOR_H_
#define ITERATOR_H_

#include "node.h"
using namespace std;

//class Node;

template <typename T>
class Iterator
{
public:
	virtual Node<T>* current() = 0;
	virtual T next() = 0;
	virtual bool hasNext() = 0;
	virtual ~Iterator(){};

private:
	 Node<T>* iHead_;
	 Node<T>* current_;
};


#endif /* ITERATOR_H_ */
