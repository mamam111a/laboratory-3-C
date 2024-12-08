

#include <boost/test/included/unit_test.hpp>

#include "../Stack.h"
#include "../header.h"



BOOST_AUTO_TEST_SUITE(TestStack)

BOOST_AUTO_TEST_CASE(TestStack_SPUSH) {
    Stack stack;
    stack.SPUSH(elementA);
    stack.SPUSH(elementB);
    stack.SPUSH(elementC);
    BOOST_CHECK_EQUAL(stack.Size(), 3); 
}
BOOST_AUTO_TEST_CASE(TestStack_SPOP) {
    Stack stack;
    stack.SPUSH(elementA);
    stack.SPUSH(elementB);
    stack.SPUSH(elementC);

    stack.SPOP();
    stack.SPOP();
    stack.SPOP();
    BOOST_CHECK_EQUAL(stack.Size(), 0); 
}

BOOST_AUTO_TEST_SUITE_END()