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

private:
  void reverse_array(std::vector<int> &nums, int start, int end);
};
#endif
