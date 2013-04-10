/*
 * listIterator.h
 *
 *  Created on: 2013-03-21
 *      Author: jun
 */

#ifndef LISTITERATOR_H_
#define LISTITERATOR_H_

#include "iterator.h"
#include "node.h"

template <typename T>
class ListIterator : public Iterator<T>
{
public:
	ListIterator(Node<T>* node);
	virtual ~ListIterator() {};
	virtual Node<T>* current();
	virtual T next();
	virtual bool hasNext();

	friend class List<T>;

private:
	Node<T>* iHead_;
	Node<T>* current_;
};

/* ListIterator */
template <typename T>
ListIterator<T>::ListIterator(Node<T>* node)
{
	iHead_ = node;
	current_ = node;
}

template <typename T>
Node<T>* ListIterator<T>::current()
{
	return current_;
}

template <typename T>
T ListIterator<T>::next()
{
	current_ = current_->next();
	return current_->get();
}

template <typename T>
bool ListIterator<T>::hasNext()
{
	return (current_->next() != iHead_);
}

/* get iterator by value*/
template <typename T>
Iterator<T>& locate(Iterator<T> &it,T value)
{
	while(it.hasNext())
		if(it.next() == value) break;
	return it;
}

#endif /* LISTITERATOR_H_ */
