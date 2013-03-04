/*
 * list.h
 *
 *  Created on: 2013-02-26
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
			ListIterator(Node* node){ iHead_ = node; current_ = node;};
			~ListIterator() {};
			virtual Node* current() { return current_;};
			virtual int next() { current_ =  current_->next();return current_->get();};
			virtual bool hasNext() {return (current_->next() != iHead_);};

			friend class List;
	private:
			Node* current_;
			Node* iHead_;
	};

public:
	//List();
	virtual ~List();
	void add(int &value);
	void remove(Iterator &iterator);
	Iterator* createIterator();
//	void print();

protected:
	virtual Iterator& locate(Iterator& it, int value);

private:
	Node head_;
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

