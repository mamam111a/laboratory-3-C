

#include <boost/test/included/unit_test.hpp>

#include "../Queue.h"
#include "../header.h"


BOOST_AUTO_TEST_SUITE(TestQueue)

BOOST_AUTO_TEST_CASE(TestQueue_QPUSH) {
    Queue queue;
    queue.QPUSH(elementA);
    queue.QPUSH(elementB);
    queue.QPUSH(elementC);
    BOOST_CHECK_EQUAL(queue.Size(), 3); 
}
BOOST_AUTO_TEST_CASE(TestQueue_QPOP) {
    Queue queue;
    queue.QPUSH(elementA);
    queue.QPUSH(elementB);
    queue.QPUSH(elementC);

    queue.QPOP();
    queue.QPOP();
    queue.QPOP();
    BOOST_CHECK_EQUAL(queue.Size(), 0); 
}

BOOST_AUTO_TEST_SUITE_END()
