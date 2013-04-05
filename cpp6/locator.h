/*
 * loc.h
 *
 *  Created on: 2013-03-22
 *      Author: jun
 */

#ifndef LOCATOR_H_
#define LOCATOR_H_

#include "iterator.h"

template <typename T>
class Locator
{
public:
	virtual Node<T>* locate(Iterator<T>* it,T value) = 0;
	virtual ~Locator(){};
};

#endif /* LOCATOR_H_ */
