

#include <boost/test/included/unit_test.hpp>

#include "../TwoList.h"
#include "../header.h"

BOOST_AUTO_TEST_SUITE(TestTwoList)

BOOST_AUTO_TEST_CASE(TestTwoList_LTWOPUSHhead) {
    TwoList twolist;
    twolist.LTWOPUSHhead(elementA);
    BOOST_CHECK_EQUAL(twolist.Size(), 1);
    twolist.LTWOPUSHhead(elementB);
    BOOST_CHECK_EQUAL(twolist.Size(), 2);
    twolist.LTWOPUSHhead(elementC);

    BOOST_CHECK_EQUAL(twolist.Size(), 3);
}
BOOST_AUTO_TEST_CASE(TestTwoList_LTWOPUSHtail) {
    TwoList twolist;
    twolist.LTWOPUSHtail(elementA);
    BOOST_CHECK_EQUAL(twolist.Size(), 1);
    twolist.LTWOPUSHtail(elementB);
    BOOST_CHECK_EQUAL(twolist.Size(), 2);
    twolist.LTWOPUSHtail(elementC);

    BOOST_CHECK_EQUAL(twolist.Size(), 3);       
}
BOOST_AUTO_TEST_CASE(TestTwoList_LTWODELhead) {
    TwoList twolist;
    twolist.LTWODELhead();
    BOOST_CHECK_EQUAL(twolist.Size(), 0);
    twolist.LTWOPUSHhead(elementA);
    twolist.LTWOPUSHhead(elementB);
    twolist.LTWOPUSHhead(elementC);

    twolist.LTWODELhead();
    BOOST_CHECK_EQUAL(twolist.Size(), 2);
    twolist.LTWODELhead();
    BOOST_CHECK_EQUAL(twolist.Size(), 1);
    twolist.LTWODELhead();
    BOOST_CHECK_EQUAL(twolist.Size(), 0); 
}
BOOST_AUTO_TEST_CASE(TestTwoList_LTWODELtail) {
    TwoList twolist;
    twolist.LTWODELtail();
    BOOST_CHECK_EQUAL(twolist.Size(), 0);
    twolist.LTWOPUSHtail(elementA);
    twolist.LTWODELtail();
    BOOST_CHECK_EQUAL(twolist.Size(), 0);
    twolist.LTWOPUSHtail(elementA);
    twolist.LTWOPUSHtail(elementB);
    twolist.LTWOPUSHtail(elementC);

    twolist.LTWODELtail();
    BOOST_CHECK_EQUAL(twolist.Size(), 2);       
}

BOOST_AUTO_TEST_CASE(TestTwoList_LTWODELvalue) {
    TwoList twolist;

    twolist.LTWOPUSHtail(elementA);
    twolist.LTWOPUSHtail(elementB);
    twolist.LTWOPUSHtail(elementC);

    twolist.LTWODELvalue(elementA);
    BOOST_CHECK_EQUAL(twolist.Size(), 2);
    BOOST_CHECK_EQUAL(twolist.SearchForTest(elementA),-1);
    twolist.LTWODELvalue(elementB);
    BOOST_CHECK_EQUAL(twolist.Size(), 1);
    BOOST_CHECK_EQUAL(twolist.SearchForTest(elementB),-1);
    twolist.LTWODELvalue(elementC);
    BOOST_CHECK_EQUAL(twolist.Size(), 0);    
    BOOST_CHECK_EQUAL(twolist.SearchForTest(elementC),-2);   
    twolist.LTWOPUSHtail(elementA);
    twolist.LTWOPUSHtail(elementB);
    twolist.LTWOPUSHtail(elementC);
    twolist.LTWODELvalue(elementB);
    BOOST_CHECK_EQUAL(twolist.Size(), 2);
}

BOOST_AUTO_TEST_CASE(TestTwoList_LTWOSEARCH) {
    TwoList twolist;

    twolist.LTWOPUSHtail(elementA);
    twolist.LTWOPUSHtail(elementB);
    twolist.LTWOPUSHtail(elementC);

    string notExist = "notExist";
    int temp1 = twolist.SearchForTest(elementA);
    int temp2 = twolist.SearchForTest(elementB);
    int temp3 = twolist.SearchForTest(elementC);

    int test = twolist.SearchForTest(notExist);

    BOOST_CHECK_EQUAL(temp1, 0);
    BOOST_CHECK_EQUAL(temp2, 1);  
    BOOST_CHECK_EQUAL(temp3, 2);
    BOOST_CHECK_EQUAL(test, -1);          
}
BOOST_AUTO_TEST_CASE(TestTwoList_SIZE) {
    TwoList twolist;

    twolist.LTWOPUSHtail(elementA);
    BOOST_CHECK_EQUAL(twolist.Size(), 1);
    twolist.LTWOPUSHtail(elementB);
    BOOST_CHECK_EQUAL(twolist.Size(), 2);
    twolist.LTWOPUSHtail(elementC);
    BOOST_CHECK_EQUAL(twolist.Size(), 3);

    twolist.LTWODELhead();
    BOOST_CHECK_EQUAL(twolist.Size(), 2); 

    twolist.LTWODELhead();
    BOOST_CHECK_EQUAL(twolist.Size(), 1);
    twolist.LTWODELhead();
    BOOST_CHECK_EQUAL(twolist.Size(), 0);
}

BOOST_AUTO_TEST_CASE(TestTwoList_DUPLICATES) {
    TwoList twolist;
    twolist.LTWOPUSHtail(elementA);
    twolist.LTWOPUSHtail(elementA); 

    BOOST_CHECK_EQUAL(twolist.Size(), 2);

    twolist.LTWODELvalue(elementA); 
    BOOST_CHECK_EQUAL(twolist.Size(), 1);
}
BOOST_AUTO_TEST_SUITE_END()
