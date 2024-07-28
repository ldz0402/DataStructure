#define CATCH_CONFIG_MAIN

#include "./TestString/TestString.h"
#include "./Tree/Tree.h"
#include "catch.hpp"

unsigned int Factorial(unsigned int number) {
  return number <= 1 ? number : Factorial(number - 1) * number;
}

TEST_CASE("Factorials are computed", "[Factorial]") {
  REQUIRE(Factorial(1) == 1);
  REQUIRE(Factorial(2) == 2);
  REQUIRE(Factorial(3) == 6);
  REQUIRE(Factorial(10) == 3628800);
}

TEST_CASE("Build a tree", "[getTree]") {
  Tree tree = getTree();
  REQUIRE(tree->val.val == 1);

  preOrder(tree);
  printf("\n");
  midOrder(tree);
  printf("\n");
  sufOrder(tree);
  printf("\n");
  BFSOrder(tree);
}