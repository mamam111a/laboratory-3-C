
#include <boost/test/included/unit_test.hpp>
#include "../AVLtree.h"

#include "Benchmark_header.h"
#include <boost/timer/timer.hpp>

string avl = "element";
BOOST_AUTO_TEST_SUITE(BenchmarkAVLtree)

BOOST_AUTO_TEST_CASE(BenchmarkAVLtree_TPUSH) {
    AVL AVLtree;
    boost::timer::cpu_timer timer;
    timer.start();
    AVLtree.TPUSH(avl);
    timer.stop();
    string name = "BenchmarkAVLtree_TPUSH";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);
}
BOOST_AUTO_TEST_CASE(BenchmarkAVLtree_TDEL) {
    AVL AVLtree;
    boost::timer::cpu_timer timer;
    AVLtree.TPUSH(avl);
    timer.start();
    AVLtree.TDEL(avl);
    timer.stop();
    string name = "BenchmarkAVLtree_TDEL";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);
}
BOOST_AUTO_TEST_CASE(BenchmarkAVLtree_TSEARCH) {
    AVL AVLtree;
    boost::timer::cpu_timer timer;
    AVLtree.TPUSH(avl);
    timer.start();
    AVLtree.TSEARCH(avl);
    timer.stop();
    string name = "BenchmarkAVLtree_TSEARCH";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);
}

BOOST_AUTO_TEST_SUITE_END()
