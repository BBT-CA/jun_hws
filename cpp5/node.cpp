/*
 * node.cpp
 *
 *  Created on: 2013-03-05
 *      Author: jun
 */


#include "node.h"
#include "data.h"

Node::Node()
{
	this->next_ = this;
}
void Node::addAfter(Node& node,int value)
{
	node.data_.set(value);
	node.next_ = this->next_;
	this->next_ = &node;
}

/* remove current node from list */
void Node::remove()
{
	if((this->data_.get()!= 0) && (this->next_->data_.get() != 0)) {
		this->data_.set(this->next_->data_.get());
		this->next_ = this->next_->next_;
	}
}

void Node::remove(Node* node)
{
	this->next_ = node;
}
/* get value */
int Node::get()
{
	return data_.get();
}

/* get next node */
Node* Node::next()
{
	return next_;
}
