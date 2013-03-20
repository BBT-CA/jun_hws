/*
 * singleLinkedList.h
 *
 *  Created on: 2013-03-07
 *      Author: jun
 */

#ifndef SINGLELINKEDLIST_H_
#define SINGLELINKEDLIST_H_

#include "list.h"

template <typename T>
class SingleLinkedList : public List<T>
{
public:
	~SingleLinkedList();
	void add(T &value);
	void remove(T &value);
	Iterator<T>* createIterator();
	void print();

private:
	Node<T> head_;
	void remove(Iterator<T>* it);
};

/* SingleLinkedList destructor */
template <typename T>
SingleLinkedList::~SingleLinkedList()
{
	Node* node = head_.next();
	while (node->next() != &head_)
	{
		Node* tmp = node;
		node = node->next();
		delete tmp;
	}
	delete node;
}

template <typename T>
void SingleLinkedList<T>::add(T &value)
{
	Iterator *it = createIterator();
	Node *nNode = new Node();
	it->current()->addAfter(*nNode,value);
	delete it;
}

template <typename T>
void SingleLinkedList<T>::remove(T &value)
{
	Iterator* it = createIterator();
	if (locate(*it,value).current()->get() == value) {
		if(it->hasNext()) {
			Node* tmp = it->current()->next();
			it->current()->remove();
			delete tmp;
		} else {
			remove(it);
		}
	} else {
		cout << "Sorry, there is no integer " << value << " in the list" << endl;
	}
	delete it;
}

template <typename T>
void SingleLinkedList<T>::remove(Iterator* it)
{
	Iterator* itL = createIterator();
	while(itL->current()->next() != it->current()) {
		itL->next();
	}
	itL->current()->remove(&head_);
	delete it->current();
	delete itL;
}

/* create iterator */
template <typename T>
Iterator* SingleLinkedList::createIterator()
{
	return new ListIterator(&head_);
}

template <typename T>
void SingleLinkedList<T>::print()
{
	Iterator<T>* it = createIterator();
	while(it->hasNext())
	{
		cout << it->next() << " " ;
	}
	cout << endl;
	delete it;
}



#endif /* SINGLELINKEDLIST_H_ */
