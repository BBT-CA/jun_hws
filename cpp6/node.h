/*
 * node.h
 *
 *  Created on: 2013-03-05
 *      Author: jun
 */

#ifndef NODE_H_
#define NODE_H_

#include "data.h"

//class Data;

template <typename T>
class Node
{
public:
	Node();
	Node(T value);
	virtual void addAfter(Node& node);
	virtual void remove();
	virtual void setNext(Node* node);
	virtual Node* next();
	virtual T get();
	virtual ~Node() {};

private:
	Node* next_;
	Data<T> data_;
};

template <typename T>
Node<T>::Node()
{
	this->next_ = this;
}

template <typename T>
Node<T>::Node(T value)
{
	this->next_ = this;
	this->data_.set(value);
}

template <typename T>
void Node<T>::addAfter(Node& node)
{
	node.next_ = this->next_;
	this->next_ = &node;
}

/* remove current node from list */
template <typename T>
void Node<T>::remove()
{
	if((this->data_.get()!= 0) && (this->next_->data_.get() != 0)) {
		this->data_.set(this->next_->data_.get());
		this->next_ = this->next_->next_;
	}
}

/* set next node of current. This method is for deleting last node in single-linked list */
template <typename T>
void Node<T>::setNext(Node* node)
{
	this->next_ = node;
}

/* get value */
template <typename T>
T Node<T>::get()
{
	return data_.get();
}

/* get next node */
template <typename T>
Node<T>* Node<T>::next()
{
	return next_;
}

#endif /* NODE_H_ */
