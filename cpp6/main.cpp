/*
 * main.cpp
 *
 *  Created on: 2013-03-11
 *      Author: jun
 */


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <time.h>
#include "list.h"
#include "iterator.h"
#include "loc.h"
#include "singleLinkedList.h"
#include "doubleLinkedList.h"
#include "sortDoubleLinkedList.h"
#include "locSortDouble.h"

using namespace std;

void print(Iterator<int>* it) {
	while(it->hasNext())
	{
		cout << it->next() << " " ;
	}
	cout << endl;
	delete it;
}

int main()
{
	srand(time(NULL));

	int num = 20; 		/* total nodes created */

	/* create a single-linked list with 21 random integer */

	Loc<int>* loc = new Loc<int>();
	SingleLinkedList<int> list(loc);
	cout << "Add the following integers to list:" << endl;
	for(int i=1;i<=num;i++)
	{
		int value = rand()%100;
		list.add(value);
		cout << value << " ";
	}
	cout << endl;
	delete loc;

	/* print list */
	cout << "Create single-linked list:" << endl;
	print(list.createIterator());

	/* remove node from list */
	int val;
	cout << "Enter the integer you want to delete: ";
	cin >> val;
	Iterator<int>* it = list.createIterator();
	while(it->hasNext()) {
		if (it->next() == val) break;
	}
	if (it->current()->get() == val) {
		list.remove(it);
	}
	delete it;

	/* print list after deleting node */
	cout << "Delete integer " << val << "..." << endl;
	print(list.createIterator());
	cout << "===========================================" << endl << endl;

	/* ===================================================*/
	/* create a double-linked list with 21 random integer */

	Loc<int>* dLoc = new Loc<int>();
	DoubleLinkedList<int> dList(dLoc);
	cout << "Add the following integers to list:" << endl;
	for(int j=1;j<=num;j++)
	{
		int dValue = rand()%100;
		dList.add(dValue);
		cout << dValue << " ";
	}
	cout << endl;

	delete dLoc;

	/* print list */
	cout << "Create double-linked list:" << endl;
	print(dList.createIterator());

	/* remove node from list */
	int dVal;
	cout << "Enter the integer you want to delete: ";
	cin >> dVal;
	Iterator<int>* itD = dList.createIterator();
	while(itD->hasNext()) {
		if (itD->next() == dVal) {
			dList.remove(itD);
			break;
		}
	}
	delete itD;

	/* print list after deleting node */
	cout << "Delete integer " << dVal << "..." << endl;
	print(dList.createIterator());
	cout << "===========================================" << endl << endl;

	/* ===================================================*/
	/* create a sorted double-linked list with 21 random integer */

	LocSortDouble<int>* sLoc = new LocSortDouble<int>();
	SortDoubleLinkedList<int> sList(sLoc);
	cout << "Add the following integers to list in ascending order:" << endl;
	for(int i=1;i<=num;i++)
	{
		int sValue = rand()%100;
		sList.add(sValue);
		cout << sValue << " ";
	}
	cout << endl;
	delete sLoc;

	/* print list */
	cout << "Create a sorted double-linked list:" << endl;
	print(sList.createIterator());

	/* remove node from list */
	int sVal;
	cout << "Enter the integer you want to delete: ";
	cin >> sVal;
	Iterator<int>* itS = sList.createIterator();
	while(itS->hasNext()) {
		if (itS->next() == sVal) {
			sList.remove(itS);
			break;
		}
	}
	delete itS;

	/* print list after deleting node */
	cout << "Delete integer " << sVal << "..." << endl;
	print(sList.createIterator());
	cout << "===========================================" << endl;

	return 0;
}

