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

using namespace std;

class List
{
protected:
	class ListIterator : public Iterator
	{
	public:
			ListIterator(Node* node);
			~ListIterator() {};
			virtual Node* current();
			virtual int next();
			virtual bool hasNext();

			friend class List;
	private:
			Node* current_;
			Node* iHead_;

	};

public:
	//List();
	virtual ~List() {};
	virtual void add(int &value) = 0;
	virtual void remove(int &value) = 0;
	virtual Iterator* createIterator() = 0;
//	virtual void print();

protected:
	virtual Iterator& locate(Iterator& it, int value);

private:
//	Node head_;
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
