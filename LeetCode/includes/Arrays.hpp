#ifndef LC_ARRAYS_H
#define LC_ARRAYS_H
#include <vector>
class ArraysSolutions {
public:
  int remove_duplicate_in_sorted_array(std::vector<int> &num);
  int max_profit(std::vector<int> &prices);
  void rotate_matrix(std::vector<int> &nums, int k);
  void rotate_matrix_inplace(std::vector<int> &nums, int k);
  bool contains_duplicates(std::vector<int> &nums);
  int single_number(std::vector<int> nums);
  std::vector<int> array_intersect(std::vector<int> nums1,
                                   std::vector<int> nums2);
  std::vector<int> plus_one(std::vector<int> &digits);
  void move_zeroes(std::vector<int> &nums);
  std::vector<int> two_sum(std::vector<int> &nums, int target);
  bool is_valid_sudoku(std::vector<std::vector<char>> &board);

private:
  void reverse_array(std::vector<int> &nums, int start, int end);
};
#endif
