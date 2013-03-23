/*
 * singleLinkedList.h
 *
 *  Created on: 2013-03-07
 *      Author: jun
 */

#ifndef SINGLELINKEDLIST_H_
#define SINGLELINKEDLIST_H_

#include "list.h"
#include "listIterator.h"
#include "loc.h"

template <typename T>
class SingleLinkedList : public List<T>
{
public:
	SingleLinkedList(Loc<T>* loc);
	~SingleLinkedList();
	void add(T &value);
	void remove(Iterator<T>* it);
	Iterator<T>* createIterator();
	Iterator<T>* locate(Iterator<T>* it,T value);

private:
	Node<T> head_;
	Loc<T>* locList_;
};

/* SingleLinkedList constructor */
template <typename T>
SingleLinkedList<T>::SingleLinkedList(Loc<T>* loc)
{
	locList_ = loc;
}

/* SingleLinkedList destructor */
template <typename T>
SingleLinkedList<T>::~SingleLinkedList()
{
	Node<T>* node = head_.next();
	while (node->next() != &head_)
	{
		Node<T>* tmp = node;
		node = node->next();
		delete tmp;
	}
	delete node;
}

template <typename T>
void SingleLinkedList<T>::add(T &value)
{
	Iterator<T> *it = createIterator();
	Node<T> *nNode = new Node<T>(value);
	it = locate(it,value);
	it->current()->addAfter(*nNode);
	delete it;
}

/*remove data from list */
template <typename T>
void SingleLinkedList<T>::remove(Iterator<T>* it)
{
		if(it->hasNext()) {
			Node<T>* tmp = it->current()->next();
			it->current()->remove();
			delete tmp;
		} else {
			Iterator<T>* itL = createIterator();
			while(itL->current()->next() != it->current()) {
				itL->next();
			}
			itL->current()->setNext(&head_);
			delete it->current();
			delete itL;
		}

}

/* create iterator */
template <typename T>
Iterator<T>* SingleLinkedList<T>::createIterator()
{
	return new ListIterator<T>(&head_);
}

/* get iterator for adding new node to the list */
template <typename T>
Iterator<T>* SingleLinkedList<T>::locate(Iterator<T>* it,T value)
{
	return locList_->locate(it,value);
}

#endif /* SINGLELINKEDLIST_H_ */
