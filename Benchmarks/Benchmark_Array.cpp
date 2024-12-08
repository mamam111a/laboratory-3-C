

#include <boost/test/included/unit_test.hpp>
#include <boost/timer/timer.hpp>
#include "../Array.h"
#include "Benchmark_header.h"

string Arr = "element";

BOOST_AUTO_TEST_SUITE(BenchmarkArray)

BOOST_AUTO_TEST_CASE(BenchmarkArray_MPUSHend) {
    Array array;
    boost::timer::cpu_timer timer;
    timer.start();
    array.MPUSHend(Arr);
    timer.stop();
    string name = "BenchmarkArray_MPUSHend";
    string result = "time: " + timer.format(9);
    SaveBenchmarkReport(name, result);
}
BOOST_AUTO_TEST_CASE(BenchmarkArray_MPUSHindex) {
    Array array;
    boost::timer::cpu_timer timer;
    timer.start();
    array.MPUSHindex(0,Arr); 
    timer.stop();
    string name = "BenchmarkArray_MPUSHindex";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);
}
BOOST_AUTO_TEST_CASE(BenchmarkArray_MDEL) {
    Array array;
    boost::timer::cpu_timer timer;
    array.MPUSHend(Arr); 
    timer.start();
    array.MDEL(0); 
    timer.stop();
    string name = "BenchmarkArray_MDEL";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);
}

BOOST_AUTO_TEST_CASE(BenchmarkArray_MREPL) {
    Array array;
    boost::timer::cpu_timer timer;
    string temp = "value";
    array.MPUSHend(Arr); 
    timer.start();
    array.MREPL(0,temp); 
    timer.stop();
    string name = "BenchmarkArray_MREPL";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);
}
BOOST_AUTO_TEST_CASE(BenchmarkArray_MGETL) {
    Array array;
    boost::timer::cpu_timer timer;
    string temp = "value";
    array.MPUSHend(Arr); 
    timer.start();
    array.MREPL(0,temp); 
    timer.stop();
    string name = "BenchmarkArray_MGETL";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);
}

BOOST_AUTO_TEST_SUITE_END()
