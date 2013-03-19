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

class CircleNode : public Node
{
public:
	CircleNode();
	void addAfter(CircleNode& node,int value);
	void addBefore(CircleNode& node,int value);
	void remove();
	CircleNode* next();
	~CircleNode() {};

private:
	CircleNode* cPrev_;
	CircleNode* cNext_;
};


#endif /* CIRCLENODE_H_ */
