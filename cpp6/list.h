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

template <typename T>
class List
{
protected:
	class ListIterator : public Iterator<T>
	{
	public:
			ListIterator(Node<T>* node);
			~ListIterator() {};
			virtual Node<T>* current();
			virtual T next();
			virtual bool hasNext();

			friend class List;
	private:
			Node<T>* current_;
			Node<T>* iHead_;

	};

public:
	//List();
	virtual ~List() {};
	virtual void add(int &value) = 0;
	virtual void remove(T &value) = 0;
	virtual Iterator<T>* createIterator() = 0;
//	virtual void print();

protected:
	virtual Iterator<T>& locate(Iterator<T>& it, T value);

private:
//	Node head_;
};


/* ListIterator */
template <typename T>
List<T>::ListIterator<T>::ListIterator(Node* node)
{
	iHead_ = node;
	current_ = node;
}

template <typename T>
Node* List<T>::ListIterator<T>::current()
{
	return current_;
}

template <typename T>
int List<T>::ListIterator<T>::next()
{
	current_ = current_->next();
	return current_->get();
}

template <typename T>
bool List<T>::ListIterator<T>::hasNext()
{
	return (current_->next() != iHead_);
}

/* get iterator by value*/
template <typename T>
Iterator<T>& List<T>::locate(Iterator<T> &it,T value)
{
	while(it.hasNext()){
	if(it.next() == value)
			break;
	}
	return it;
}
/*
void List::print()
{
	Iterator* it = createIterator();
	while(it->hasNext())
	{
		cout << it->next() << " " ;
	}
	cout << endl;
	delete it;
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
