/*
 * doubleLinkedList.h
 *
 *  Created on: 2013-03-07
 *      Author: jun
 */

#ifndef DOUBLELINKEDLIST_H_
#define DOUBLELINKEDLIST_H_

#include "list.h"
#include "circleNode.h"

template <typename T>
class DoubleLinkedList : public List<T>
{
public:
	DoubleLinkedList(Loc<T>* loc);
	~DoubleLinkedList();
	void add(T &value);
	void remove(Iterator<T>* it);
	Iterator<T>* createIterator();
	Iterator<T>* locate(Iterator<T>* it,T value);

private:
	CircleNode<T> head_;
	Loc<T>* locList_;
};

/* DobleLinkedList constructor */
template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(Loc<T>* loc)
{
	locList_ = loc;
}

/* DobleLinkedList destructor */
template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
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
void DoubleLinkedList<T>::add(T &value)
{
	Iterator<T> *it = createIterator();
	CircleNode<T> *nNode = new CircleNode<T>(value);
	it = locate(it,value);
	dynamic_cast<CircleNode<T>*>(it->current())->addAfter(*nNode,value);
	delete it;
}

/* remove data from list */
template <typename T>
void DoubleLinkedList<T>::remove(Iterator<T>* it)
{
	CircleNode<T>* tmp = dynamic_cast<CircleNode<T>*>(it->current());
	it->current()->remove();
	delete tmp;
}

/* create iterator */
template <typename T>
Iterator<T>* DoubleLinkedList<T>::createIterator()
{
	return new ListIterator<T>(&head_);
}

/* get iterator for adding new node to the list */
template <typename T>
Iterator<T>* DoubleLinkedList<T>::locate(Iterator<T>* it,T value)
{
	return locList_->locate(it,value);
}



#endif /* DOUBLELINKEDLIST_H_ */
