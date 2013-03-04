/*
 * sortList.cpp
 *
 *  Created on: 2013-02-26
 *      Author: jun
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "sortList.h"
#include "list.h"
using namespace std;

/* return iterator by value */
Iterator& SortList::locate(Iterator& it, int value)
{
	while(it.hasNext())
		if (it.next() > value) break;
	return it;
}


