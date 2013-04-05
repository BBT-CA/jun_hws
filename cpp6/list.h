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
#include "locator.h"

using namespace std;

template <typename T>
class List
{
public:
	virtual ~List() {};
	virtual void add(T &value) = 0;
	virtual void remove(Iterator<T>* it) = 0;
	virtual Iterator<T>* createIterator() = 0;
//	virtual Node<T>* locate(Iterator<T>* it,T value)=0;
//	void setLocator(Locator<T>* loc);

private:
	Node<T> head_;
	Locator<T>* locList_;
};
/*
template <typename T>
void List<T>::setLocator(Locator<T>* loc)
{
	this->locList_ = loc;
}
*/
#endif /* LIST_H_ */

/* question: add constructor functions in UML */
/*
 public:
  List(Locator &); // strategy design pattern
  add(Data &d);
 protected:
 virtual Iterator & locate(Data d);  //subclass only need to override locate()

 */
