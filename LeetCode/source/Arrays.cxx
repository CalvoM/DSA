#include "../includes/Arrays.hpp"
#include <algorithm>
#include <catch2/catch_message.hpp>
#include <iostream>

int ArraysSolutions::remove_duplicate_in_sorted_array(std::vector<int> &nums) {
  int final_size = 0;
  int next_idx = 1;
  int curr_idx = 0;
  while (next_idx < nums.size()) {
    if (nums[curr_idx] == nums[next_idx]) {
      next_idx++;
    } else if (nums[curr_idx] != nums[next_idx]) {
      curr_idx++;
      nums[curr_idx] = nums[next_idx];
      next_idx++;
    }
  }
  std::cout << "Output of " << curr_idx << std::endl;

  return curr_idx + 1;
}

int ArraysSolutions::max_profit(std::vector<int> &prices) {
  int curr_min = prices[0], curr_max = prices[0];
  int curr_idx = 1;
  int total_profit = 0;
  while (curr_idx < prices.size()) {
    if (prices[curr_idx] < prices[curr_idx - 1]) {
      total_profit += curr_max - curr_min;
      curr_min = prices[curr_idx];
      curr_max = prices[curr_idx];
    } else if (prices[curr_idx] > prices[curr_idx - 1]) {
      curr_max = prices[curr_idx];
    }
    if (prices[curr_idx] >= prices[curr_idx - 1] &&
        curr_idx == prices.size() - 1) {
      curr_max = prices[curr_idx];
      total_profit += curr_max - curr_min;
    }
    curr_idx++;
  }
  return total_profit;
}
