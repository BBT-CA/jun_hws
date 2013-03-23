/*
 * loc.h
 *
 *  Created on: 2013-03-22
 *      Author: jun
 */

#ifndef LOC_H_
#define LOC_H_

#include "iterator.h"

template <typename T>
class Loc
{
public:
	virtual Iterator<T>* locate(Iterator<T>* it,T value);
	virtual ~Loc(){};
};

template <typename T>
Iterator<T>* Loc<T>::locate(Iterator<T>* it,T value)
{
	while(it->hasNext())
		it->next();
	return it;
}

#endif /* LOC_H_ */
