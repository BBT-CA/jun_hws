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
#include "singleLinkedList.h"
#include "doubleLinkedList.h"
#include "sortDoubleLinkedList.h"

using namespace std;

int main()
{
	srand(time(NULL));

	int num = 20; 		/* total nodes created */

	/* create a single-linked list with 21 random integer */

	SingleLinkedList list;
	for(int i=1;i<=num;i++)
	{
		int value = rand()%100;
		list.add(value);
	}

	/* print list */
	cout << "creating single-linked list:" << endl;
	list.print();

	/* remove node from list */
	int val;
	cout << "Please enter the integer you want to delete: ";
	cin >> val;
	list.remove(val);

	/* print list after deleting node */
	cout << "after deleting integer " << val << "..." << endl;
	list.print();
	cout << "===========================================" << endl << endl;

	/* ===================================================*/
	/* create a double-linked list with 21 random integer */

	DoubleLinkedList dList;
	for(int j=1;j<=num;j++)
	{
		int dValue = rand()%100;
		dList.add(dValue);
	}

	/* print list */
	cout << "creating double-linked list:" << endl;
	dList.print();

	/* remove node from list */
	int dVal;
	cout << "Please enter the integer you want to delete: ";
	cin >> dVal;
	dList.remove(dVal);

	/* print list after deleting node */
	cout << "after deleting integer " << dVal << "..." << endl;
	dList.print();
	cout << "===========================================" << endl << endl;

	/* ===================================================*/
	/* create a sorted double-linked list with 21 random integer */

	SortDoubleLinkedList sList;
	for(int i=1;i<=num;i++)
	{
		int sValue = rand()%100;
		sList.add(sValue);
	}

	/* print list */
	cout << "creating a sorted double-linked list:" << endl;
	sList.print();

	/* remove node from list */
	int sVal;
	cout << "Please enter the integer you want to delete: ";
	cin >> sVal;
	sList.remove(sVal);

	/* print list after deleting node */
	cout << "after deleting integer " << sVal << "..." << endl;
	sList.print();
	cout << "===========================================" << endl;

	return 0;
}

