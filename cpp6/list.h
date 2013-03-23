/*
 * list.h
 *
 *  Created on: 2013-03-05
 *      Author: jun
 */

#ifndef LIST_H_
#define LIST_H_


#include "node.h"
#include "iterator.h"
#include "loc.h"

using namespace std;

template <typename T>
class List
{
public:
	virtual ~List() {};
	virtual void add(int &value) = 0;
	virtual void remove(Iterator<T>* it) = 0;
	virtual Iterator<T>* createIterator() = 0;
	virtual Iterator<T>* locate(Iterator<T>* it,T value)=0;

private:
	Node<T> head_;
	Loc<T>* locList_;
};


#endif /* LIST_H_ */

/* question: add constructor functions in UML */
/*
 public:
  List(Locator &); // strategy design pattern
  add(Data &d);
 protected:
 virtual Iterator & locate(Data d);  //subclass only need to override locate()

 */
