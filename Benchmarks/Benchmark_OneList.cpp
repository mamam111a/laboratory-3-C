

#include <boost/test/included/unit_test.hpp>

#include "../OneList.h"

#include "Benchmark_header.h"
#include <boost/timer/timer.hpp>

string one = "element";
BOOST_AUTO_TEST_SUITE(BenchmarkOneList)

BOOST_AUTO_TEST_CASE(BenchmarkOneList_LONEPUSHhead) {
    OneList onelist;
    boost::timer::cpu_timer timer;
    timer.start();
    onelist.LONEPUSHhead(one);
    timer.stop();
    string name = "BenchmarkOneList_LONEPUSHhead";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);
}
BOOST_AUTO_TEST_CASE(BenchmarkOneList_LONEPUSHtail) {
    OneList onelist;
    boost::timer::cpu_timer timer;
    timer.start();
    onelist.LONEPUSHtail(one);
    timer.stop();
    string name = "BenchmarkOneList_LONEPUSHtail";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);
}
BOOST_AUTO_TEST_CASE(BenchmarkOneList_LONEDELhead) {
    OneList onelist;
    boost::timer::cpu_timer timer;
    onelist.LONEPUSHtail(one);
    timer.start();
    onelist.LONEDELhead();
    timer.stop();
    string name = "BenchmarkOneList_LONEDELhead";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);

}
BOOST_AUTO_TEST_CASE(BenchmarkOneList_LONEDELtail) {
    OneList onelist;
    boost::timer::cpu_timer timer;
    onelist.LONEPUSHtail(one);
    timer.start();
    onelist.LONEDELtail();
    timer.stop();
    string name = "BenchmarkOneList_LONEDELtail";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);
}

BOOST_AUTO_TEST_CASE(BenchmarkOneList_LONEDELvalue) {
    OneList onelist;
    boost::timer::cpu_timer timer;
    onelist.LONEPUSHtail(one);
    timer.start();
    onelist.LONEDELvalue(one);
    timer.stop();
    string name = "BenchmarkOneList_LONEDELvalue";
    string result = "time: " + timer.format(9) + "s";
    SaveBenchmarkReport(name, result);

}


BOOST_AUTO_TEST_SUITE_END()
