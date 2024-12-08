

#include <boost/test/included/unit_test.hpp>

#include "../OneList.h"
#include "../header.h"


BOOST_AUTO_TEST_SUITE(TestOneList)

BOOST_AUTO_TEST_CASE(TestOneList_LONEPUSHhead) {
    OneList onelist;
    onelist.LONEPUSHhead(elementA);
    BOOST_CHECK_EQUAL(onelist.Size(), 1);
    onelist.LONEPUSHhead(elementB);
    BOOST_CHECK_EQUAL(onelist.Size(), 2);
    onelist.LONEPUSHhead(elementC);

    BOOST_CHECK_EQUAL(onelist.Size(), 3);
}
BOOST_AUTO_TEST_CASE(TestOneList_LONEPUSHtail) {
    OneList onelist;
    onelist.LONEPUSHtail(elementA);
    BOOST_CHECK_EQUAL(onelist.Size(), 1);
    onelist.LONEPUSHtail(elementB);
    BOOST_CHECK_EQUAL(onelist.Size(), 2);
    onelist.LONEPUSHtail(elementC);

    BOOST_CHECK_EQUAL(onelist.Size(), 3);       
}
BOOST_AUTO_TEST_CASE(TestOneList_LONEDELhead) {
    OneList onelist;
    onelist.LONEDELhead();
    BOOST_CHECK_EQUAL(onelist.Size(), 0);
    onelist.LONEPUSHhead(elementA);
    onelist.LONEPUSHhead(elementB);
    onelist.LONEPUSHhead(elementC);

    onelist.LONEDELhead();
    BOOST_CHECK_EQUAL(onelist.Size(), 2);
    onelist.LONEDELhead();
    BOOST_CHECK_EQUAL(onelist.Size(), 1);
    onelist.LONEDELhead();
    BOOST_CHECK_EQUAL(onelist.Size(), 0); 
}
BOOST_AUTO_TEST_CASE(TestOneList_LONEDELtail) {
    OneList onelist;
    onelist.LONEDELtail();
    BOOST_CHECK_EQUAL(onelist.Size(), 0);
    onelist.LONEPUSHtail(elementA);
    onelist.LONEDELtail();
    BOOST_CHECK_EQUAL(onelist.Size(), 0);
    onelist.LONEPUSHtail(elementA);
    onelist.LONEPUSHtail(elementB);
    onelist.LONEPUSHtail(elementC);

    onelist.LONEDELtail();
    BOOST_CHECK_EQUAL(onelist.Size(), 2);       
}

BOOST_AUTO_TEST_CASE(TestOneList_LONEDELvalue) {
    OneList onelist;

    onelist.LONEPUSHtail(elementA);
    onelist.LONEPUSHtail(elementB);
    onelist.LONEPUSHtail(elementC);

    onelist.LONEDELvalue(elementA);
    BOOST_CHECK_EQUAL(onelist.Size(), 2);
    BOOST_CHECK_EQUAL(onelist.SearchForTest(elementA),-1);
    onelist.LONEDELvalue(elementB);
    BOOST_CHECK_EQUAL(onelist.Size(), 1);
    BOOST_CHECK_EQUAL(onelist.SearchForTest(elementB),-1);
    onelist.LONEDELvalue(elementC);
    BOOST_CHECK_EQUAL(onelist.Size(), 0);    
    BOOST_CHECK_EQUAL(onelist.SearchForTest(elementC),-2);   
    onelist.LONEPUSHtail(elementA);
    onelist.LONEPUSHtail(elementB);
    onelist.LONEPUSHtail(elementC);
    onelist.LONEDELvalue(elementB);
    BOOST_CHECK_EQUAL(onelist.Size(), 2);
}

BOOST_AUTO_TEST_CASE(TestOneList_LONESEARCH) {
    OneList onelist;

    onelist.LONEPUSHtail(elementA);
    onelist.LONEPUSHtail(elementB);
    onelist.LONEPUSHtail(elementC);

    string notExist = "notExist";
    int temp1 = onelist.SearchForTest(elementA);
    int temp2 = onelist.SearchForTest(elementB);
    int temp3 = onelist.SearchForTest(elementC);

    int test = onelist.SearchForTest(notExist);

    BOOST_CHECK_EQUAL(temp1, 0);
    BOOST_CHECK_EQUAL(temp2, 1);  
    BOOST_CHECK_EQUAL(temp3, 2);
    BOOST_CHECK_EQUAL(test, -1);          
}
BOOST_AUTO_TEST_CASE(TestOneList_SIZE) {
    OneList onelist;

    onelist.LONEPUSHtail(elementA);
    BOOST_CHECK_EQUAL(onelist.Size(), 1);
    onelist.LONEPUSHtail(elementB);
    BOOST_CHECK_EQUAL(onelist.Size(), 2);
    onelist.LONEPUSHtail(elementC);
    BOOST_CHECK_EQUAL(onelist.Size(), 3);

    onelist.LONEDELhead();
    BOOST_CHECK_EQUAL(onelist.Size(), 2); 

    onelist.LONEDELhead();
    BOOST_CHECK_EQUAL(onelist.Size(), 1);
    onelist.LONEDELhead();
    BOOST_CHECK_EQUAL(onelist.Size(), 0);
}

BOOST_AUTO_TEST_CASE(TestOneList_DUPLICATES) {
    OneList onelist;
    onelist.LONEPUSHtail(elementA);
    onelist.LONEPUSHtail(elementA); 

    BOOST_CHECK_EQUAL(onelist.Size(), 2);

    onelist.LONEDELvalue(elementA); 
    BOOST_CHECK_EQUAL(onelist.Size(), 1);
}
BOOST_AUTO_TEST_SUITE_END()
