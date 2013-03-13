/*
 * circleNode.h
 *
 *  Created on: 2013-03-07
 *      Author: jun
 */

#ifndef CIRCLENODE_H_
#define CIRCLENODE_H_

#include "data.h"
#include "node.h"

class Data;

class CircleNode : public Node
{
public:
	CircleNode();
	void addAfter(CircleNode& node,int value);
	void addBefore(CircleNode& node,int value);
	void remove();

private:
	CircleNode* prev_;
	CircleNode* next_;
	Data data_;
};


#endif /* CIRCLENODE_H_ */
