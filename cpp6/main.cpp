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
#include <math.h>
#include "list.h"
#include "iterator.h"
#include "locator.h"
#include "locatorSingle.h"
#include "locatorDouble.h"
#include "locatorSort.h"
#include "singleLinkedList.h"
#include "doubleLinkedList.h"
#include "array.h"

using namespace std;

template <typename T>
void print(Iterator<T>* it) {
	while(it->hasNext())
	{
		cout << it->next() << " " ;
	}
	cout << endl;
	delete it;
}

void printArray(Iterator<Array>* it) {
while(it->hasNext())
{
	cout << it->next().getKey() << "," << it->next().getName() << endl;
}
delete it;
}

int main()
{
	srand(time(NULL));

	int num = 20; 		/* total nodes created */

	/* create a single-linked list with 21 random integer */

	LocatorSingle<int>* loc = new LocatorSingle<int>();

	SingleLinkedList<int> list(loc);
	for(int i=1;i<=num;i++)
	{
		int value = rand()%100;
		if(value != 0) {
			list.add(value);
		} else {
			i--;
		}
	}
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
	/* create a double-linked list with char*/

	char name[9] = {'J','U','N','H','U','I','W','E','N'};
	int len = 9;

	LocatorDouble<char>* dLoc = new LocatorDouble<char>();
	DoubleLinkedList<char> dList(dLoc);

	for(int j=0;j<len;j++)
	{
		char dValue =  name[j];
		dList.add(dValue);
	}

	delete dLoc;

	/* print list */
	cout << "Create double-linked list:" << endl;
	print(dList.createIterator());

	/* remove node from list */
	char dVal;
	cout << "Enter the character you want to delete: ";
	cin >> dVal;
	Iterator<char>* itD = dList.createIterator();
	while(itD->hasNext()) {
		if (itD->next() == dVal) {
			dList.remove(itD);
			break;
		}
	}
	delete itD;

	/* print list after deleting node */
	cout << "Delete char " << dVal << "..." << endl;
	print(dList.createIterator());
	cout << "===========================================" << endl << endl;

	/* ===================================================*/
	/* create a sorted double-linked list with char*/

	LocatorSort<char>* sLoc = new LocatorSort<char>();
	DoubleLinkedList<char> sList(sLoc);

	for(int j=0;j<len;j++)
	{
		char sValue =  name[j];
		sList.add(sValue);
	}

	delete dLoc;

	/* print list */
	cout << "Create SORTED double-linked list:" << endl;
	print(sList.createIterator());

	/* remove node from list */
	char sVal;
	cout << "Enter the character you want to delete: ";
	cin >> sVal;
	Iterator<char>* itS = sList.createIterator();
	while(itS->hasNext()) {
		if (itS->next() == sVal) {
			sList.remove(itS);
			break;
		}
	}
	delete itS;

	/* print list after deleting node */
	cout << "Delete char " << dVal << "..." << endl;
	print(sList.createIterator());
	cout << "===========================================" << endl << endl;

	/* ===================================================*/
	/* create a sorted double-linked list with Array object */

	LocatorSort<Array>* aLoc = new LocatorSort<Array>();
	DoubleLinkedList<Array> aList(aLoc);

	char* sName;
	int key;
	for(int i=0;i<3;i++)
	{
		cout << "Enter key and name: ";
		cin >> key >> sName;

		Array* array = new Array(key,sName);

		/* add data to list */
		aList.add(*array);

	}
	delete aLoc;

	/* print list */
	cout << "Create a sorted double-linked list:" << endl;
	printArray(aList.createIterator());

	/* remove node from list */
	int aKey;
	char* aName;
	cout << "Enter the data you want to delete: ";
	cin >> aKey >> aName;
	Array* aVal = new Array(aKey,aName);
	Iterator<Array>* itA = aList.createIterator();
	while(itA->hasNext()) {
		if (itA->next() == *aVal) {
			aList.remove(itA);
			break;
		}
	}
	delete itA;

	/* print list after deleting node */
	cout << "After deleting data " << "..." << endl;
	printArray(aList.createIterator());
	cout << "===========================================" << endl;



	return 0;
}

