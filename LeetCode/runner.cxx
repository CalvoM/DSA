#include "includes/Arrays.hpp"
#include "includes/DP.hpp"
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

TEST_CASE("Array Question 3", "[Rotate Matrix]") {
  ArraysSolutions solutions;
  std::vector<int> orig0 = {1, 2, 3, 4, 5, 6, 7};
  std::vector<int> ans0 = {5, 6, 7, 1, 2, 3, 4};
  solutions.rotate_matrix_inplace(orig0, 3);
  REQUIRE(orig0 == ans0);
}

TEST_CASE("Array Question 4", "[Intersection Array]") {
  ArraysSolutions solutions;
  std::vector<int> orig0 = {1, 2, 2, 1};
  std::vector<int> orig1 = {2, 2};
  std::vector<int> ans0 = {2, 2};
  REQUIRE(solutions.array_intersect(orig0, orig1) == ans0);
  std::vector<int> orig2 = {4, 9, 5};
  std::vector<int> orig3 = {9, 4, 9, 8, 4};
  std::vector<int> ans1 = {4, 9};
  REQUIRE(solutions.array_intersect(orig2, orig3) == ans1);
}

TEST_CASE("Array Question 5", "[Plus One]") {
  ArraysSolutions solutions;
  std::vector<int> orig0 = {4, 3, 2, 1};
  std::vector<int> ans0 = {4, 3, 2, 2};
  REQUIRE(solutions.plus_one(orig0) == ans0);
  std::vector<int> orig1 = {9};
  std::vector<int> ans1 = {1, 0};
  REQUIRE(solutions.plus_one(orig1) == ans1);
  std::vector<int> orig2 = {0};
  std::vector<int> ans2 = {1};
  REQUIRE(solutions.plus_one(orig2) == ans2);
  std::vector<int> orig3 = {6, 1, 4, 5, 3, 9, 0, 1, 9, 5,
                            1, 8, 6, 7, 0, 5, 5, 4, 3};
  std::vector<int> ans3 = {6, 1, 4, 5, 3, 9, 0, 1, 9, 5,
                           1, 8, 6, 7, 0, 5, 5, 4, 4};
  REQUIRE(solutions.plus_one(orig3) == ans3);
  std::vector<int> orig4 = {7, 2, 8, 5, 0, 9, 1, 2, 9, 5, 3, 6, 6,
                            7, 3, 2, 8, 4, 3, 7, 9, 5, 7, 7, 4, 7,
                            4, 9, 4, 7, 0, 1, 1, 1, 7, 4, 0, 0, 6};
  std::vector<int> ans4 = {7, 2, 8, 5, 0, 9, 1, 2, 9, 5, 3, 6, 6,
                           7, 3, 2, 8, 4, 3, 7, 9, 5, 7, 7, 4, 7,
                           4, 9, 4, 7, 0, 1, 1, 1, 7, 4, 0, 0, 7};
  REQUIRE(solutions.plus_one(orig4) == ans4);
}
TEST_CASE("Array Question 6", "[Move Zeroes]") {
  ArraysSolutions solutions;
  std::vector<int> orig0 = {0, 1, 0, 3, 12};
  std::vector<int> ans0 = {1, 3, 12, 0, 0};
  solutions.move_zeroes(orig0);
  REQUIRE(orig0 == ans0);
  std::vector<int> orig1 = {2, 1};
  std::vector<int> ans1 = {2, 1};
  solutions.move_zeroes(orig1);
  REQUIRE(orig1 == ans1);
}

TEST_CASE("Array Question 7", "[Valid Sudoku]") {
  ArraysSolutions solutions;
  std::vector<std::vector<char>> orig0 = {
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  REQUIRE(solutions.is_valid_sudoku(orig0) == true);
  std::vector<std::vector<char>> orig1 = {
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '5', '.', '7', '9'}};
  REQUIRE(solutions.is_valid_sudoku(orig1) == false);
  std::vector<std::vector<char>> orig2 = {
      {'.', '.', '.', '.', '5', '.', '.', '1', '.'},
      {'.', '4', '.', '3', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '3', '.', '.', '1'},
      {'8', '.', '.', '.', '.', '.', '.', '2', '.'},
      {'.', '.', '2', '.', '7', '.', '.', '.', '.'},
      {'.', '1', '5', '.', '.', '.', '.', '.', '.'},
      {'.', '.', '.', '.', '.', '2', '.', '.', '.'},
      {'.', '2', '.', '9', '.', '.', '.', '.', '.'},
      {'.', '.', '4', '.', '.', '.', '.', '.', '.'}};
  REQUIRE(solutions.is_valid_sudoku(orig2) == false);
}
TEST_CASE("Dynamic Programming", "[Steps]") {
  DPSolutions dp;
  REQUIRE(dp.climb_stairs(2) == 2);
  REQUIRE(dp.climb_stairs(3) == 3);
  REQUIRE(dp.climb_stairs(4) == 5);
  REQUIRE(dp.climb_stairs(5) == 8);
}
TEST_CASE("Dynamic Programming", "[Prices]") {
  DPSolutions dp;
  std::vector<int> prices0 = {7, 1, 5, 3, 6, 4};
  REQUIRE(dp.max_profit(prices0) == 5);
  std::vector<int> prices1 = {7, 6, 5, 4, 3, 2};
  REQUIRE(dp.max_profit(prices1) == 0);
}
TEST_CASE("Dynamic Programming", "[Fib Tabs]") {
  DPSolutions dp;
  REQUIRE(dp.fib_tab(8) == 21);
  REQUIRE(dp.fib_tab(6) == 8);
  REQUIRE(dp.fib_tab(9) == 34);
  REQUIRE(dp.fib_tab(10) == 55);
  REQUIRE(dp.fib_tab(11) == 89);
  REQUIRE(dp.fib_tab(12) == 144);
  REQUIRE(dp.fib_tab(50) == 12586269025);
}
TEST_CASE("Dynamic Programming", "[Can Sum]") {
  DPSolutions dp;
  std::vector<int> orig = {2, 3, 5};
  std::vector<std::vector<int>> ans = {{2, 2, 2, 2}, {2, 3, 3}, {3, 5}};
  auto actual_ans = dp.combination_sum(orig, 8);
  REQUIRE(actual_ans.size() == 3);
  std::vector<int> orig1 = {2};
  std::vector<int> ans1 = {};
  std::vector<std::vector<int>> actual_ans1 = dp.combination_sum(orig1, 1);
  REQUIRE(actual_ans1.size() == 0);
  std::vector<int> orig3 = {2, 3, 6, 7};
  std::vector<std::vector<int>> ans3 = {{2, 3, 2}, {7}};
  std::vector<std::vector<int>> actual_ans3 = dp.combination_sum(orig3, 7);
  REQUIRE(actual_ans3 == ans3);
  REQUIRE(actual_ans3.size() == 2);
}
