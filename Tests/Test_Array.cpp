

#include <boost/test/included/unit_test.hpp>
#include "../Array.h"
#include "../header.h"


BOOST_AUTO_TEST_SUITE(TestArray)

BOOST_AUTO_TEST_CASE(TestArray_MPUSHend) {
    Array array;
    array.MPUSHend(elementA);
    BOOST_CHECK_EQUAL(array.MSIZE(), 1);
    array.MPUSHend(elementB);
    BOOST_CHECK_EQUAL(array.MSIZE(), 2);
    array.MPUSHend(elementC);
    BOOST_CHECK_EQUAL(array.MSIZE(), 3);
    string A = array.MGETL(0);
    string B = array.MGETL(1);
    string C = array.MGETL(2);
    A.erase(remove(A.begin(), A.end(), ' '), A.end());
    B.erase(remove(B.begin(), B.end(), ' '), B.end());
    C.erase(remove(C.begin(), C.end(), ' '), C.end());
    BOOST_CHECK_EQUAL(A, elementA);
    BOOST_CHECK_EQUAL(B, elementB);
    BOOST_CHECK_EQUAL(C, elementC);  

}
BOOST_AUTO_TEST_CASE(TestArray_MPUSHindex) {
    Array array;
    array.MPUSHindex(0, elementA);
    BOOST_CHECK_EQUAL(array.MSIZE(), 1);
    array.MPUSHindex(1, elementB);
    BOOST_CHECK_EQUAL(array.MSIZE(), 2);
    array.MPUSHindex(2, elementC);
    BOOST_CHECK_EQUAL(array.MSIZE(), 3);
    string A = array.MGETL(0);
    string B = array.MGETL(1);
    string C = array.MGETL(2);
    A.erase(remove(A.begin(), A.end(), ' '), A.end());
    B.erase(remove(B.begin(), B.end(), ' '), B.end());
    C.erase(remove(C.begin(), C.end(), ' '), C.end());
    BOOST_CHECK_EQUAL(A, elementA);
    BOOST_CHECK_EQUAL(B, elementB);
    BOOST_CHECK_EQUAL(C, elementC);
    string temp = "hehe";
    array.MPUSHindex(1, temp);
    string temp1 = array.MGETL(1);
    string temp2 = array.MGETL(2);
    string temp3 = array.MGETL(3);
    temp1.erase(remove(temp1.begin(), temp1.end(), ' '), temp1.end());
    temp2.erase(remove(temp2.begin(), temp2.end(), ' '), temp2.end());
    temp3.erase(remove(temp3.begin(), temp3.end(), ' '), temp3.end());
    BOOST_CHECK_EQUAL(temp1, temp);
    BOOST_CHECK_EQUAL(temp2, elementB);
    BOOST_CHECK_EQUAL(temp3, elementC);
}
BOOST_AUTO_TEST_CASE(TestArray_MDEL) {
    Array array;
    array.MPUSHend(elementA);
    array.MPUSHend(elementB);
    array.MPUSHend(elementC);

    array.MDEL(0);
    BOOST_CHECK_EQUAL(array.MSIZE(), 2);
    array.MDEL(0);
    BOOST_CHECK_EQUAL(array.MSIZE(), 1);
    
    string temp = array.MGETL(0);
    temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
    BOOST_CHECK_EQUAL(temp, elementC);

    array.MPUSHend(elementA);
    array.MPUSHend(elementB);
    array.MPUSHend(elementC);

    array.MDEL(0);
    BOOST_CHECK_EQUAL(array.MSIZE(), 3);
    array.MDEL(0);
    BOOST_CHECK_EQUAL(array.MSIZE(), 2);
    array.MDEL(0);
    BOOST_CHECK_EQUAL(array.MSIZE(), 1);
    array.MDEL(0);
    int size = array.MSIZE();
    BOOST_CHECK_EQUAL(size, 0); 

    array.MPUSHend(elementA);
    array.MPUSHend(elementB);
    array.MPUSHend(elementC);

    array.MDEL(-1); 
    array.MDEL(1001); 
    BOOST_CHECK_EQUAL(array.MSIZE(), 3);
}

BOOST_AUTO_TEST_CASE(TestArray_MREPL) {
    Array array;

    array.MPUSHend(elementA);
    array.MPUSHend(elementB);
    array.MPUSHend(elementC);
    
    string temp = "GGG";
    array.MREPL(0, temp);
    BOOST_CHECK_EQUAL(array.MSIZE(), 3);
    array.MREPL(1, temp);
    BOOST_CHECK_EQUAL(array.MSIZE(), 3);
    array.MREPL(2, temp);
    BOOST_CHECK_EQUAL(array.MSIZE(), 3);
    string A = array.MGETL(0);
    string B = array.MGETL(1);
    string C = array.MGETL(2);
    A.erase(remove(A.begin(), A.end(), ' '), A.end());
    B.erase(remove(B.begin(), B.end(), ' '), B.end());
    C.erase(remove(C.begin(), C.end(), ' '), C.end());
    BOOST_CHECK_EQUAL(A, temp);
    BOOST_CHECK_EQUAL(B, temp);
    BOOST_CHECK_EQUAL(C, temp);

    string temp1 = "value";
    array.MREPL(-1, temp1); 
    array.MREPL(1001, temp1); 

    A = array.MGETL(0);
    B = array.MGETL(1);
    C = array.MGETL(2);
    A.erase(remove(A.begin(), A.end(), ' '), A.end());
    B.erase(remove(B.begin(), B.end(), ' '), B.end());
    C.erase(remove(C.begin(), C.end(), ' '), C.end());
    BOOST_CHECK_EQUAL(A, temp); 
    BOOST_CHECK_EQUAL(B, temp);
    BOOST_CHECK_EQUAL(C, temp); 

}
BOOST_AUTO_TEST_CASE(TestArray_MGETL) {
    Array array;
    array.MPUSHend(elementA);
    array.MPUSHend(elementB);
    array.MPUSHend(elementC);

    string A = array.MGETL(0);
    string B = array.MGETL(1);
    string C = array.MGETL(2);
    A.erase(remove(A.begin(), A.end(), ' '), A.end());
    B.erase(remove(B.begin(), B.end(), ' '), B.end());
    C.erase(remove(C.begin(), C.end(), ' '), C.end());
    BOOST_CHECK_EQUAL(A, elementA);
    BOOST_CHECK_EQUAL(B, elementB);
    BOOST_CHECK_EQUAL(C, elementC);

    BOOST_CHECK_EQUAL(array.MGETL(-1), "ERROR"); 
    BOOST_CHECK_EQUAL(array.MGETL(1001), "ERROR"); 
}

BOOST_AUTO_TEST_CASE(TestArray_MSIZE) {
    Array array;
    BOOST_CHECK_EQUAL(array.MSIZE(), 0);

    array.MPUSHend(elementA);
    BOOST_CHECK_EQUAL(array.MSIZE(), 1);

    array.MPUSHend(elementB);
    BOOST_CHECK_EQUAL(array.MSIZE(), 2);

    array.MDEL(1);
    BOOST_CHECK_EQUAL(array.MSIZE(), 1);
}

BOOST_AUTO_TEST_CASE(TestArray_DUPLICATES) {
    Array array;
    array.MPUSHend(elementA);
    array.MPUSHend(elementA);
    string temp1 = array.MGETL(0);
    string temp2 = array.MGETL(1);
    temp1.erase(remove(temp1.begin(), temp1.end(), ' '), temp1.end());
    temp2.erase(remove(temp2.begin(), temp2.end(), ' '), temp2.end());
    BOOST_CHECK_EQUAL(temp1, elementA); 
    BOOST_CHECK_EQUAL(temp2, elementA); 
}

BOOST_AUTO_TEST_CASE(TestArray_EMPTY) {
    Array array;
    string temp1 = "";
    array.MPUSHend(temp1);
    string temp2 = array.MGETL(0);
    temp2.erase(remove(temp2.begin(), temp2.end(), ' '), temp2.end());
    BOOST_CHECK_EQUAL(temp2, temp1); 
}


BOOST_AUTO_TEST_SUITE_END()
