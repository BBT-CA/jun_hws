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
#include "circleNode.h"

using namespace std;
/* constructor. set the node automatically point to itself */
CircleNode::CircleNode()
{
	this->cPrev_ = this;
	this->cNext_ = this;
}

/* add new node after current */
void CircleNode::addAfter(CircleNode& node,int value)
{
	node.data_.set(value);
	this->cNext_->cPrev_ = &node;
	node.cNext_ = this->cNext_;
	node.cPrev_ = this;
	this->cNext_ = &node;
}

/* add new node before current */
void CircleNode::addBefore(CircleNode& node,int value)
{
	node.data_.set(value);
	this->cPrev_->cNext_ = &node;
	node.cNext_ = this;
	node.cPrev_ = this->cPrev_;
	this->cPrev_ = &node;
}

/* remove current node from list */
void CircleNode::remove()
{
	cPrev_->cNext_ = cNext_;
	cNext_->cPrev_ = cPrev_;
}

/* get next node */
CircleNode* CircleNode::next()
{
	return cNext_;
}




