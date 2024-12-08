

#include <boost/test/included/unit_test.hpp>

#include "../TwoList.h"

#include "Benchmark_header.h"
#include <boost/timer/timer.hpp>

string two = "element";
BOOST_AUTO_TEST_SUITE(BenchmarkTwoList)

BOOST_AUTO_TEST_CASE(BenchmarkTwoList_LTWOPUSHhead) {
    TwoList twolist;
    boost::timer::cpu_timer timer;
    timer.start();
    twolist.LTWOPUSHhead(two);
    timer.stop();
    string name = "BenchmarkTwoList_LTWOPUSHhead";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);
}
BOOST_AUTO_TEST_CASE(BenchmarkTwoList_LTWOPUSHtail) {
    TwoList twolist;
    boost::timer::cpu_timer timer;
    timer.start();
    twolist.LTWOPUSHtail(two);
    timer.stop();
    string name = "BenchmarkTwoList_LTWOPUSHtail";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);
}
BOOST_AUTO_TEST_CASE(BenchmarkTwoList_LTWODELhead) {
    TwoList twolist;
    boost::timer::cpu_timer timer;
    twolist.LTWOPUSHtail(two);
    timer.start();
    twolist.LTWODELhead();
    timer.stop();
    string name = "BenchmarkTwoList_LTWODELhead";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);

}
BOOST_AUTO_TEST_CASE(BenchmarkTwoList_LTWODELtail) {
    TwoList twolist;
    boost::timer::cpu_timer timer;
    twolist.LTWOPUSHtail(two);
    timer.start();
    twolist.LTWODELtail();
    timer.stop();
    string name = "BenchmarkTwoList_LTWODELtai";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);
}

BOOST_AUTO_TEST_CASE(BenchmarkTwoList_LTWODELvalue) {
    TwoList twolist;
    boost::timer::cpu_timer timer;
    twolist.LTWOPUSHtail(two);
    timer.start();
    twolist.LTWODELvalue(two);
    timer.stop();
    string name = "BenchmarkTwoList_LTWODELvalue";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);

}

BOOST_AUTO_TEST_SUITE_END()
