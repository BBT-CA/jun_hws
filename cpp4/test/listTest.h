#ifndef TEST_listTest
#define TEST_listTest

#ifdef ECUT_MAIN

#include "cppunit/extensions/HelperMacros.h"
#include "list.h"

class listTest : public CPPUNIT_NS::TestFixture {
private:
	List list;
public:
	void setUp();
	void testadd();
	void testremove();
	void testcreateIterator();
	CPPUNIT_TEST_SUITE(listTest);
	CPPUNIT_TEST(testadd);
	CPPUNIT_TEST(testremove);
	CPPUNIT_TEST(testcreateIterator);
	CPPUNIT_TEST_SUITE_END();
};

#endif /* ECUT_MAIN */

#endif /*LISTTEST*/
