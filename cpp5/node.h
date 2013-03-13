/*
 * node.h
 *
 *  Created on: 2013-03-05
 *      Author: jun
 */

#ifndef NODE_H_
#define NODE_H_

#include "data.h"

class Data;

class Node
{
public:
	Node();
	virtual void addAfter(Node& node,int value);
	virtual void remove();
	Node* next();
	int get();
	virtual ~Node() {};

private:
	Node* next_;
	Data data_;
};


#endif /* NODE_H_ */
