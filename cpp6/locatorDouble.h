/*
 * locatorDouble.h
 *
 *  Created on: 2013-03-29
 *      Author: jun
 */

#ifndef LOCATORDOUBLE_H_
#define LOCATORDOUBLE_H_

#include "locator.h"
#include "iterator.h"

template <typename T>
class LocatorDouble : public Locator<T>
{
public:
	virtual Node<T>* locate(Iterator<T>* it,T value);
	virtual ~LocatorDouble(){};
};

template <typename T>
Node<T>* LocatorDouble<T>::locate(Iterator<T>* it,T value)
{
	while(it->hasNext())
		it->next();
	return it->current();
}


#endif /* LOCATORDOUBLE_H_ */
