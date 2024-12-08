

#include <boost/test/included/unit_test.hpp>

#include "../HashTable.h"
#include "../header.h"

string A = "a";
string B = "b";
string C = "c";

BOOST_AUTO_TEST_SUITE(TestHashTable)

BOOST_AUTO_TEST_CASE(TestHashTable_HPUSH) {
    HashTable hashtable;
    hashtable.HPUSH(A, elementA);
    hashtable.HPUSH(B, elementB);
    hashtable.HPUSH(C, elementC);

    string temp1 = hashtable.HGET(A);
    string temp2 = hashtable.HGET(B);
    string temp3 = hashtable.HGET(C);

    BOOST_CHECK_EQUAL(temp1, elementA);
    BOOST_CHECK_EQUAL(temp2, elementB);
    BOOST_CHECK_EQUAL(temp3, elementC);
}
BOOST_AUTO_TEST_CASE(TestHashTable_HDEL) {
    HashTable hashtable;
    hashtable.HPUSH(A, elementA);
    hashtable.HPUSH(B, elementB);
    hashtable.HPUSH(C, elementC);

    hashtable.HDEL(A);
    hashtable.HDEL(B);
    hashtable.HDEL(C);
    BOOST_CHECK_EQUAL(hashtable.Size(), 0);       
}
BOOST_AUTO_TEST_CASE(TestHashTable_HGET) {
    HashTable hashtable;

    hashtable.HPUSH(A, elementA);
    hashtable.HPUSH(B, elementB);
    hashtable.HPUSH(C, elementC);

    string temp1 = hashtable.HGET(A);
    string temp2 = hashtable.HGET(B);
    string temp3 = hashtable.HGET(C);
    
    BOOST_CHECK_EQUAL(temp1, elementA);
    BOOST_CHECK_EQUAL(temp2, elementB);
    BOOST_CHECK_EQUAL(temp3, elementC);      

    hashtable.HDEL(A);
    BOOST_CHECK_EQUAL(hashtable.HGET(A), "\n\nThe key was not found\n\n");
}

BOOST_AUTO_TEST_CASE(TestHashTable_SIZE) {
    HashTable hashtable;

    hashtable.HPUSH(A, elementA);
    hashtable.HPUSH(B, elementB);
    hashtable.HPUSH(C, elementC);
    BOOST_CHECK_EQUAL(hashtable.Size(), 3);

    hashtable.HDEL(A);
    BOOST_CHECK_EQUAL(hashtable.Size(), 2);
    
    hashtable.HDEL(B);
    hashtable.HDEL(C);
    BOOST_CHECK_EQUAL(hashtable.Size(), 0);
}
BOOST_AUTO_TEST_CASE(TestHashTable_HASHFUNC) {
    HashTable hashtable;

    int index = hashtable.HashFunc(elementA);

    BOOST_CHECK(index >= 0);
    BOOST_CHECK(index < 1000);
}
BOOST_AUTO_TEST_CASE(TestHashTable_COLLISION) {
    HashTable hashtable;

    hashtable.HPUSH(elementA, elementB);
    hashtable.HPUSH(elementA, elementC);
    hashtable.HPUSH(elementC, elementA);

    string temp1 = hashtable.HGET(elementA);
    string temp2 = hashtable.HGET(elementC);

    BOOST_CHECK_EQUAL(temp1, elementC);
    BOOST_CHECK_EQUAL(temp2, elementA);
}

BOOST_AUTO_TEST_CASE(TestHashTable_EMPTY) {
    HashTable hashtable;

    BOOST_CHECK_EQUAL(hashtable.Size(), 0); 
    hashtable.HDEL(A);
    BOOST_CHECK_EQUAL(hashtable.Size(), 0);
}

BOOST_AUTO_TEST_SUITE_END()
