/*
 * circleNode.cpp
 *
 *  Created on: 2013-03-07
 *      Author: jun
 */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "circleNode.h"
#include "data.h"

using namespace std;
/* constructor. set the node automatically point to itself */
CircleNode::CircleNode()
{
	this->prev_ = this;
	this->next_ = this;
}

/* add new node after current */
void CircleNode::addAfter(CircleNode& node,int value)
{
	node.data_.set(value);
	this->next_->prev_ = &node;
	node.next_ = this->next_;
	node.prev_ = this;
	this->next_ = &node;

	cout << this->data_.get() <<" " << next_->data_.get() << " " << next_->next_->data_.get() <<endl;
}

/* add new node before current */
void CircleNode::addBefore(CircleNode& node,int value)
{
	node.data_.set(value);
	this->prev_->next_ = &node;
	node.next_ = this;
	node.prev_ = this->prev_;
	this->prev_ = &node;
}

/* remove current node from list */
void CircleNode::remove()
{cout << "circle node remove" << endl;
cout <<  prev_->get() <<" " << this->get() << " " << next_->get() <<endl;
	prev_->next_ = next_;
	next_->prev_ = prev_;
}






