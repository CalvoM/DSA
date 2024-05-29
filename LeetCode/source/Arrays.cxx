#include "../includes/Arrays.hpp"
#include <algorithm>
#include <bitset>
#include <catch2/catch_message.hpp>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>

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
int ArraysSolutions::single_number(std::vector<int> nums) {
  int xor_num = nums[0];
  for (int k = 1; k < nums.size(); k++)
    xor_num = xor_num ^ nums[k];
  return xor_num;
}
std::vector<int> ArraysSolutions::array_intersect(std::vector<int> nums1,
                                                  std::vector<int> nums2) {
  std::vector<int> intersects;
  std::unordered_map<int, int> intersect_maps;
  std::unordered_map<int, int> intersect_maps2;
  for (auto n1 : nums1) {
    auto it = intersect_maps.find(n1);
    if (it != intersect_maps.end()) {
      intersect_maps.insert({n1, it->second + 1});
      it->second++;
    } else {
      intersect_maps.insert({n1, 1});
    }
  }
  for (auto n2 : nums2) {
    auto it = intersect_maps2.find(n2);
    if (it != intersect_maps2.end()) {
      intersect_maps2.insert({n2, it->second + 1});
      it->second++;
    } else {
      intersect_maps2.insert({n2, 1});
    }
  }
  for (auto m2 : intersect_maps2) {
    auto it = intersect_maps.find(m2.first);
    if (it != intersect_maps.end()) {
      int m2_count = m2.second;
      int m1_count = it->second;
      auto el_count = std::min(m2_count, m1_count);
      while (el_count > 0) {
        intersects.push_back(m2.first);
        el_count--;
      }
    }
  }
  return intersects;
}

std::vector<int> ArraysSolutions::plus_one(std::vector<int> &digits) {
  for (int i = digits.size() - 1; i >= 0; --i) {
    if (digits[i] + 1 > 9) {
      digits[i] = 0;
      if (i == 0)
        digits.insert(digits.begin(), 1);
    } else {
      digits[i] += 1;
      break;
    }
  }
  return digits;
}
void ArraysSolutions::move_zeroes(std::vector<int> &nums) {
  int non_zero_idx = 0;
  for (int idx = 0; idx < nums.size(); idx++) {
    if (nums[idx] != 0) {
      nums[non_zero_idx++] = nums[idx];
    }
  }
  while (non_zero_idx < nums.size()) {
    nums[non_zero_idx++] = 0;
  }
}
std::vector<int> ArraysSolutions::two_sum(std::vector<int> &nums, int target) {
  std::vector<int> res;
  for (int k = 0; k < nums.size(); k++) {
    for (int j = k; j < nums.size(); j++) {
      if (nums[k] + nums[j] == target) {
        res.push_back(k);
        res.push_back(j);
        return res;
      }
    }
  }
  return res;
}
bool ArraysSolutions::is_valid_sudoku(std::vector<std::vector<char>> &board) {
  // check row
  std::set<char> buffer_set;
  for (auto row : board) {
    buffer_set.clear();
    for (auto item : row) {
      if (item != '.') {
        if (!buffer_set.insert(item).second)
          return false;
      }
    }
  }
  // check col
  for (int col = 0; col < board[0].size(); col++) {
    buffer_set.clear();
    for (auto row : board) {
      if (row[col] != '.') {
        if (!buffer_set.insert(row[col]).second)
          return false;
      }
    }
  }
  // check box
  for (int box_row_idx = 0; box_row_idx < board[0].size(); box_row_idx += 3) {
    for (int box_col_idx = 0; box_col_idx < board[0].size(); box_col_idx += 3) {
      int inner_col_idx = box_col_idx, inner_row_idx = box_row_idx;
      buffer_set.clear();
      while (inner_row_idx < box_row_idx + 3) {
        inner_col_idx = box_col_idx;
        while (inner_col_idx < box_col_idx + 3) {
          if (board[inner_row_idx][inner_col_idx] != '.') {
            if (!buffer_set.insert(board[inner_row_idx][inner_col_idx]).second)
              return false;
          }
          inner_col_idx++;
        }
        inner_row_idx++;
      }
    }
  }
  return true;
}
