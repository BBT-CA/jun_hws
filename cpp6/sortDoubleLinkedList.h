/*
 * sortDoubleLinkedList.h
 *
 *  Created on: 2013-03-07
 *      Author: jun
 */

#ifndef SORTDOUBLELINKEDLIST_H_
#define SORTDOUBLELINKEDLIST_H_

#include "list.h"
#include "iterator.h"
#include "circleNode.h"

template <typename T>
class SortDoubleLinkedList : public List<T>
{
public:
	SortDoubleLinkedList(Loc<T>* loc);
	~SortDoubleLinkedList();
	void add(int &value);
	void remove(Iterator<T>* it);
	Iterator<T>* createIterator();
	Iterator<T>* locate(Iterator<T>* it,T value);

private:
	CircleNode<T> head_;
	Loc<T>* locList_;
};

/* SortDobleLinkedList constructor */
template <typename T>
SortDoubleLinkedList<T>::SortDoubleLinkedList(Loc<T>* loc)
{
	locList_ = loc;
}

/* SortDobleLinkedList destructor */
template <typename T>
SortDoubleLinkedList<T>::~SortDoubleLinkedList()
{
	CircleNode<T>* node = head_.next();
	while (node->next() != &head_)
	{
		CircleNode<T>* tmp = node;
		node->remove();
		node = tmp->next();
		delete tmp;
	}
}

/* add data to the list */
template <typename T>
void SortDoubleLinkedList<T>::add(int &value)
{
	Iterator<T> *it = createIterator();
	CircleNode<T> *nNode = new CircleNode<T>(value);
 	it = locate(it,value);
	if((it->current()->next() == &head_) && (it->current()->get() < value))
		dynamic_cast<CircleNode<T>*>(it->current())->addAfter(*nNode,value);
	else
		dynamic_cast<CircleNode<T>*>(it->current())->addBefore(*nNode,value);
	delete it;
}

/* remove data from list */
template <typename T>
void SortDoubleLinkedList<T>::remove(Iterator<T>* it)
{
	CircleNode<T>* tmp = dynamic_cast<CircleNode<T>*>(it->current());
	it->current()->remove();
	delete tmp;
}

/* create iterator */
template <typename T>
Iterator<T>* SortDoubleLinkedList<T>::createIterator()
{
	return new ListIterator<T>(&head_);
}

/* get iterator for adding new node in ascending order */
template <typename T>
Iterator<T>* SortDoubleLinkedList<T>::locate(Iterator<T>* it,T value)
{
	return locList_->locate(it,value);
}

#endif /* SORTDOUBLELINKEDLIST_H_*/
