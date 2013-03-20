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
	virtual ~DoubleLinkedList();
	virtual void add(T &value);
	void remove(T &value);
	Iterator<T>* createIterator();
	void print();

private:
	CircleNode<T> head_;
};


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
	CircleNode<T> *nNode = new CircleNode<T>();
	dynamic_cast<CircleNode<T>*>(it->current())->addAfter(*nNode,value);
	delete it;
}

/* remove data from list */
template <typename T>
void DoubleLinkedList<T>::remove(T &value)
{
	Iterator<T>* it = createIterator();
	if (locate(*it,value).current()->get() == value) {
		if(locate(*it,value).current() != &head_) {
			it->current()->remove();
			delete it->current();
		}
	} else {
		cout << "Sorry, there is no integer " << value << " in the list" << endl;
	}
	delete it;
}

/* create iterator */
template <typename T>
Iterator<T>* DoubleLinkedList<T>::createIterator()
{
	return new ListIterator(&head_);
}

template <typename T>
void DoubleLinkedList<T>::print()
{
	Iterator* it = createIterator();
	while(it->hasNext())
	{
		cout <<it->next() << " " ;
	}
	cout << endl;
	delete it;
}




#endif /* DOUBLELINKEDLIST_H_ */
