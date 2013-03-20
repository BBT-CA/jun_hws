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
	virtual void addAfter(Node& node,T value);
	virtual void remove();
	virtual void remove(Node* node);
	virtual Node* next();
	T get();
	virtual ~Node() {};

protected:
	Data<T> data_;

private:
	Node* next_;
};

template <typename T>
Node<T>::Node()
{
	this->next_ = this;
}

template <typename T>
void Node<T>::addAfter(Node& node,T value)
{
	node.data_.set(value);
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

template <typename T>
void Node<T>::remove(Node* node)
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
