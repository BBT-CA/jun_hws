
#ifdef ECUT_MAIN
#include "listTest.h"

#include "list.h"

CPPUNIT_TEST_SUITE_REGISTRATION(listTest);

void listTest::setUp()
{
	for(int i=100;i<110;i++){
		list.add(i);
	}
}

void listTest::testadd() {
	int val = 99;
	list.add(val);
	Iterator *it = list.createIterator();
	CPPUNIT_ASSERT(it->next()==99);
}

void listTest::testremove() {
	Iterator *it = list.createIterator();

	for(int i=0;i<5;i++)
		it->next();
	list.remove(*it);
	CPPUNIT_ASSERT(it->next()==106);
	delete it;
}

void listTest::testcreateIterator() {
	Iterator *it = list.createIterator();
	CPPUNIT_ASSERT(it->next()==100);
	delete it;
}


#endif /* ECUT_MAIN */

