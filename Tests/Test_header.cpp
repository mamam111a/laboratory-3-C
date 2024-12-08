
#include <boost/test/included/unit_test.hpp>
#include "../header.h"

BOOST_AUTO_TEST_SUITE(TestHeader)
BOOST_AUTO_TEST_CASE(TestHeader_ARGUMENTS) {

    string filename;
    string query;
    const char* args[] = {"./program", "--file", "file.txt", "--query", "CREATE TABLE meme"};
    int argc = 5;

    inputArguments(argc, const_cast<char**>(args), filename, query); //const_cast убирает const

    BOOST_CHECK_EQUAL(filename, "file.txt");
    BOOST_CHECK_EQUAL(query, "CREATE TABLE meme");
}

BOOST_AUTO_TEST_CASE(TestHeader_EMPTY) {
    string filename;
    string query;
    const char* args[] = {"./program"};
    int argc = sizeof(args) / sizeof(args[0]);

    inputArguments(argc, const_cast<char**>(args), filename, query);

    BOOST_CHECK(filename.empty());
    BOOST_CHECK(query.empty());
}

BOOST_AUTO_TEST_CASE(TestHeader_MISSINGS) {
    string filename1;
    string query1;
    string filename2;
    string query2;
    int argc = 4;

    // --file
    const char* args1[] = {"./program", "--file", "--query", "CREATE TABLE meme"};
    inputArguments(argc, const_cast<char**>(args1), filename1, query1);
    BOOST_CHECK(query1.empty());

    // --query
    const char* args2[] = {"./program", "--file", "file.txt", "--query"};
    inputArguments(argc, const_cast<char**>(args2), filename2, query2);
    BOOST_CHECK(query2.empty());

}

BOOST_AUTO_TEST_SUITE_END()