/*
 * node.cpp
 *
 *  Created on: 2013-02-26
 *      Author: jun
 */

#include "node.h"
#include "data.h"

/* constructor. set the node automatically point to itself */
Node::Node()
{
	this->prev_ = this;
	this->next_ = this;
}

/* add new node after current */
void Node::addAfter(Node& node,int value)
{
	node.data_.set(value);
	this->next_->prev_ = &node;
	node.next_ = this->next_;
	node.prev_ = this;
	this->next_ = &node;
}

/* add new node before current */
void Node::addBefore(Node& node,int value)
{
	node.data_.set(value);
	this->prev_->next_ = &node;
	node.next_ = this;
	node.prev_ = this->prev_;
	this->prev_ = &node;
}

/* remove current node from list */
void Node::remove()
{
	prev_->next_ = next_;
	next_->prev_ = prev_;
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


