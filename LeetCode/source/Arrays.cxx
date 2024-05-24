#include "../includes/Arrays.hpp"
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
