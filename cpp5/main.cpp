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
	cout << "===========================================" << endl;

	/* remove node from list */
	int val;
	cout << "Please enter the integer you want to delete: ";
	cin >> val;
	list.remove(val);

	/* print list after deleting node */
	cout << endl << "single-lined list after deleting integer " << val << endl;
	list.print();
	cout << "===========================================" << endl;

	/* ===================================================*/
	/* create a double-linked list with 21 random integer */

	DoubleLinkedList dList;
	for(int j=1;j<=num;j++)
	{
		int dValue = rand()%100;
cout << "add "<< j << endl;
		dList.add(dValue);
	}

	/* print list */
	cout << "creating double-linked list:" << endl;

	dList.print();
	cout << "===========================================" << endl;

	/* remove node from list */
	int dVal;
	cout << "Please enter the integer you want to delete: ";
	cin >> dVal;
	dList.remove(dVal);
	cout << endl;

	/* print list after deleting node */
	cout << "double-linked list after deleting integer " << dVal << endl;
	dList.print();
	cout << "===========================================" << endl;
}

