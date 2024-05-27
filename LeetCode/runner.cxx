#include "includes/Arrays.hpp"
#include <catch2/catch_message.hpp>
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("Array Questions 1", "[Remove duplicates]") {
  ArraysSolutions solutions;
  std::vector<int> orig = {1, 2, 3, 4};
  std::vector<int> expected = {1, 2, 3, 4};
  REQUIRE(solutions.remove_duplicate_in_sorted_array(orig) == 4);
  for (int k = 0; k < 4; k++) {
    REQUIRE(orig[k] == expected[k]);
  }
  std::vector<int> orig1 = {1, 2, 2, 3, 3, 4, 4, 4, 5};
  std::vector<int> expected1 = {1, 2, 3, 4, 5};
  REQUIRE(solutions.remove_duplicate_in_sorted_array(orig1) == 5);
  for (int k = 0; k < 5; k++) {
    REQUIRE(orig1[k] == expected1[k]);
  }
  std::vector<int> orig2 = {1, 2, 2, 2, 3, 7, 7, 10, 13, 13, 14};
  std::vector<int> expected2 = {1, 2, 3, 7, 10, 13, 14};
  REQUIRE(solutions.remove_duplicate_in_sorted_array(orig2) == 7);
  for (int k = 0; k < 7; k++) {
    REQUIRE(orig2[k] == expected2[k]);
  }
  std::vector<int> orig3 = {1, 1};
  std::vector<int> expected3 = {1};
  REQUIRE(solutions.remove_duplicate_in_sorted_array(orig3) == 1);
  for (int k = 0; k < 1; k++) {
    REQUIRE(orig3[k] == expected3[k]);
  }
}

TEST_CASE("Array Questions 2", "[Max Profit]") {
  ArraysSolutions solutions;
  std::vector<int> orig0 = {7, 6, 5, 4, 3, 2, 1};
  int ans0 = 0;
  REQUIRE(solutions.max_profit(orig0) == ans0);
  std::vector<int> orig1 = {1, 2, 3, 4, 5};
  int ans1 = 4;
  REQUIRE(solutions.max_profit(orig1) == ans1);
  std::vector<int> orig = {7, 1, 5, 3, 6, 4};
  int ans = 7;
  REQUIRE(solutions.max_profit(orig) == ans);
}
