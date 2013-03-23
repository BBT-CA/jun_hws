/*
 * circleNode.h
 *
 *  Created on: 2013-03-07
 *      Author: jun
 */

#ifndef CIRCLENODE_H_
#define CIRCLENODE_H_

//#include "data.h"
#include "node.h"

//class Data;
template <typename T>
class CircleNode : public Node<T>
{
public:
	CircleNode();
	CircleNode(T value);
	void addAfter(CircleNode& node,T value);
	void addBefore(CircleNode& node,T value);
	void remove();
	CircleNode* next();
	~CircleNode() {};

private:
	CircleNode* cPrev_;
	CircleNode* cNext_;
};

/* constructor. set the node automatically point to itself */
template <typename T>
CircleNode<T>::CircleNode(T value)
{
	this->data_.set(value);
	this->cPrev_ = this;
	this->cNext_ = this;
}

template <typename T>
CircleNode<T>::CircleNode()
{
	this->cPrev_ = this;
	this->cNext_ = this;
}

/* add new node after current */
template <typename T>
void CircleNode<T>::addAfter(CircleNode& node,T value)
{
	node.data_.set(value);
	this->cNext_->cPrev_ = &node;
	node.cNext_ = this->cNext_;
	node.cPrev_ = this;
	this->cNext_ = &node;
}

/* add new node before current */
template <typename T>
void CircleNode<T>::addBefore(CircleNode& node,T value)
{
	node.data_.set(value);
	this->cPrev_->cNext_ = &node;
	node.cNext_ = this;
	node.cPrev_ = this->cPrev_;
	this->cPrev_ = &node;
}

/* remove current node from list */
template <typename T>
void CircleNode<T>::remove()
{
	cPrev_->cNext_ = cNext_;
	cNext_->cPrev_ = cPrev_;
}

/* get next node */
template <typename T>
CircleNode<T>* CircleNode<T>::next()
{
	return cNext_;
}

#endif /* CIRCLENODE_H_ */
