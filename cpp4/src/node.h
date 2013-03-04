/*
 * node.h
 *
 *  Created on: 2013-02-26
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
	void addAfter(Node& node,int value);
	void addBefore(Node& node,int value);
	void remove();
	Node* next();
	int get();

private:
	Node* prev_;
	Node* next_;
	Data data_;
};


#endif /* NODE_H_ */
