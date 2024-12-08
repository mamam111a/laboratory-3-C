
#include <boost/test/included/unit_test.hpp>
#include "../AVLtree.h"
#include "../header.h"

BOOST_AUTO_TEST_SUITE(TestAVLtree)

BOOST_AUTO_TEST_CASE(TestAVLtree_TPUSH) {
    AVL AVLtree;
    
    AVLtree.TPUSH(elementA);
    BOOST_CHECK_EQUAL(AVLtree.Size(), 1);
    AVLtree.TPUSH(elementB);
    BOOST_CHECK_EQUAL(AVLtree.Size(), 2);
    AVLtree.TPUSH(elementC);
    BOOST_CHECK_EQUAL(AVLtree.Size(), 3);
}
BOOST_AUTO_TEST_CASE(TestAVLtree_TDEL) {
    AVL AVLtree;

    AVLtree.TPUSH(elementA);
    AVLtree.TPUSH(elementB);
    AVLtree.TPUSH(elementC);

    AVLtree.TDEL(elementA);
    BOOST_CHECK_EQUAL(AVLtree.Size(), 2);
    AVLtree.TDEL(elementB);
    BOOST_CHECK_EQUAL(AVLtree.Size(), 1);
    AVLtree.TDEL(elementC);
    BOOST_CHECK_EQUAL(AVLtree.Size(), 0);

    string temp1 = "5";
    string temp2 = "10";
    string temp3 = "15";
    string temp4 = "20";
    string temp5 = "30";
    AVLtree.TPUSH(temp1);
    AVLtree.TPUSH(temp2); 
    AVLtree.TPUSH(temp3);
    AVLtree.TPUSH(temp4); 
    AVLtree.TPUSH(temp5);

    AVLtree.TDEL(temp4);
    AVLtree.TDEL(temp3);
    AVLtree.TDEL(temp2);
    AVLtree.TDEL(temp1);
    AVLtree.TDEL(temp5);
}
BOOST_AUTO_TEST_CASE(TestAVLtree_TSEARCH) {
    AVL AVLtree;

    AVLtree.TPUSH(elementA);
    AVLtree.TPUSH(elementB);
    AVLtree.TPUSH(elementC);

    AVLtree.TDEL(elementA);
    BOOST_CHECK_EQUAL(AVLtree.Find(elementA), false);  
    BOOST_CHECK_EQUAL(AVLtree.Find(elementB), true); 
    BOOST_CHECK_EQUAL(AVLtree.Find(elementC), true); 
    AVLtree.TDEL(elementB);
    BOOST_CHECK_EQUAL(AVLtree.Find(elementA), false);  
    BOOST_CHECK_EQUAL(AVLtree.Find(elementB), false); 
    BOOST_CHECK_EQUAL(AVLtree.Find(elementC), true); 
    AVLtree.TDEL(elementC);
    BOOST_CHECK_EQUAL(AVLtree.Find(elementA), false);  
    BOOST_CHECK_EQUAL(AVLtree.Find(elementB), false); 
    BOOST_CHECK_EQUAL(AVLtree.Find(elementC), false); 
}
BOOST_AUTO_TEST_CASE(TestAVLtree_DUPLICATES) {
    AVL AVLtree;
    string temp = "50";

    AVLtree.TPUSH(temp);
    AVLtree.TPUSH(temp); 

    BOOST_CHECK_EQUAL(AVLtree.Size(), 1); 
    BOOST_CHECK_EQUAL(AVLtree.GetRoot()->key, temp);
}

BOOST_AUTO_TEST_CASE(TestAVLtree_BALANCE) {
    AVL AVLtree;
    string temp1 = "5";
    string temp2 = "10";
    string temp3 = "15";
    string temp4 = "20";
    string temp5 = "30";
    AVLtree.TPUSH(temp1);
    AVLtree.TPUSH(temp2); 
    AVLtree.TPUSH(temp3);
    AVLtree.TPUSH(temp4); 
    AVLtree.TPUSH(temp5);
    BOOST_CHECK_EQUAL(AVLtree.Size(), 5);
    BOOST_CHECK_EQUAL(AVLtree.THeight(AVLtree.GetRoot()), 3);
}
BOOST_AUTO_TEST_CASE(TestAVLtree_MINVALUE) {
    AVL AVLtree;
    string temp1 = "10";
    string temp2 = "5";
    string temp3 = "15";
    AVLtree.TPUSH(temp1);
    AVLtree.TPUSH(temp2); 
    AVLtree.TPUSH(temp3);
    BOOST_CHECK_EQUAL(AVLtree.TMinValueLeftNode(AVLtree.GetRoot())->key,temp1);
}
BOOST_AUTO_TEST_CASE(TestAVLtree_CHECKROOT) {
    AVL AVLtree;

    string element1 = "30";
    string element2 = "20";
    string element3 = "40";
    AVLtree.TPUSH(element1);
    AVLtree.TPUSH(element2);
    AVLtree.TPUSH(element3);
    BOOST_CHECK_EQUAL(AVLtree.GetRoot()->key, "30"); 
}

BOOST_AUTO_TEST_SUITE_END()
