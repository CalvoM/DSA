#include "../includes/Arrays.hpp"
#include <bitset>
#include <catch2/catch_message.hpp>
#include <iostream>
#include <set>

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

void ArraysSolutions::rotate_matrix(std::vector<int> &nums, int k) {
  std::vector<int> buffer(nums.size());
  for (int idx = 0; idx < nums.size(); idx++) {
    int new_pos = (idx + k) % nums.size();
    buffer[new_pos] = nums[idx];
  }
  nums = buffer;
}

void ArraysSolutions::rotate_matrix_inplace(std::vector<int> &nums, int k) {
  int separator = k % nums.size();
  this->reverse_array(nums, 0, nums.size() - 1);
  this->reverse_array(nums, 0, separator - 1);
  this->reverse_array(nums, separator, nums.size() - 1);
}

void ArraysSolutions::reverse_array(std::vector<int> &nums, int start,
                                    int end) {
  while (end >= start) {
    int buf = nums[start];
    nums[start] = nums[end];
    nums[end] = buf;
    start++;
    end--;
  }
}
bool ArraysSolutions::contains_duplicates(std::vector<int> &nums) {
  std::set<int> final_nums;
  for (auto num : nums) {
    if (final_nums.insert(num).second == false) {
      return true;
    }
  }
  return false;
}
