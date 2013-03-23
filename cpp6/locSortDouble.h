/*
 * locSortDouble.h
 *
 *  Created on: 2013-03-23
 *      Author: jun
 */

#ifndef LOCSORTDOUBLE_H_
#define LOCSORTDOUBLE_H_

#include "loc.h"
#include "iterator.h"

template <typename T>
class LocSortDouble : public Loc<T>
{
public:
	Iterator<T>* locate(Iterator<T>* it,T value);
	~LocSortDouble(){};
};

template <typename T>
Iterator<T>* LocSortDouble<T>::locate(Iterator<T>*it,T value)
{
	while(it->hasNext())
	{
		if(it->next() > value) break;
	}
	return it;
}

#endif /* LOCSORTDOUBLE_H_ */
