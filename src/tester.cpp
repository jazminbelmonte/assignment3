#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>
#include <sstream>
#include "sorted_collection.h"
using namespace std;

TEST_CASE("Sorted Collection") {
  SortedCollection<int> one;
  one << 19 << 9 << 2 << 8 << 7 << 12 
      << 17 << 0 << 11 << 6 << 3 << 1;

  REQUIRE(one[0] == 0);
  REQUIRE(one[11] == 19);
  REQUIRE_THROWS(one[20]);
  REQUIRE_THROWS(one[20] = 1);
  REQUIRE((one << 13).size()== 13);
}

TEST_CASE("Sorted Collection - add") {
  SortedCollection<int> one;
  one + 19 + 9 + 2 + 8 + 7 + 12 
      + 17 + 0 + 11 + 6 + 3 + 1;

  REQUIRE(one[1] == 1);
  REQUIRE(one[10] == 17);
  REQUIRE_THROWS(one[13]);
  REQUIRE_THROWS(one[13] = 1);
  REQUIRE((one << 13).size()== 13);
}

TEST_CASE("Sorted Collection - remove") {
  SortedCollection<int> one;
  one + 19 + 9 + 2 + 8 ;

  REQUIRE(one.size() == 4);
  one - 2;
  REQUIRE(one.size() == 2);
  REQUIRE(one[1] == 8);
  REQUIRE(one[0] == 2);
  REQUIRE_THROWS(one[4]);
  REQUIRE_THROWS(one[4] = 1);
  --one;
  REQUIRE(one.size() == 1);
  REQUIRE(one[0] == 2);
  REQUIRE_THROWS(one[2]);
  --one;
  REQUIRE(one.size() == 0);
}

TEST_CASE("Sorted Collection - constructors") {
  SortedCollection<int> one(4);
  
  REQUIRE(one[0] == 0);
  REQUIRE(one[3] == 0);
  REQUIRE_THROWS(one[5]);
  REQUIRE_THROWS(one[5] = 1);
  one << -1 << -10;
  stringstream sout;
  sout << one;
  REQUIRE(sout.str() == "-10 -1 0 0 0 0 ");

  SortedCollection<int> two(one);
  REQUIRE(two[0] == -10);
  REQUIRE(two[3] == 0);
  REQUIRE_THROWS(two[7]);
  REQUIRE_THROWS(two[11] = 1);
  sout.str("");
  sout << two;
  REQUIRE(sout.str() == "-10 -1 0 0 0 0 ");
}
