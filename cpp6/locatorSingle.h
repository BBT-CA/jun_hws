/*
 * locatorSingle.h
 *
 *  Created on: 2013-04-04
 *      Author: jun
 */

#ifndef LOCATORSINGLE_H_
#define LOCATORSINGLE_H_

#include "iterator.h"
#include "locator.h"

template <typename T>
class LocatorSingle : public Locator<T>
{
public:
	virtual Node<T>* locate(Iterator<T>* it,T value);
	virtual ~LocatorSingle(){};
};

template <typename T>
Node<T>* LocatorSingle<T>::locate(Iterator<T>* it,T value)
{
	while(it->hasNext())
		it->next();
	return it->current();
}


#endif /* LOCATORSINGLE_H_ */
