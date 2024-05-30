#include "DP.hpp"
long int DP::fibonacci(long int index, bool optimized) {
  if (optimized) {
    std::map<long int, long int> memo;
    return this->_fibonacci_optimized(index, memo);

  } else
    return this->_fibonacci(index);
}
long int DP::_fibonacci(long int index) {
  if (index <= 2)
    return 1;
  return this->_fibonacci(index - 1) + this->_fibonacci(index - 2);
}
long int DP::_fibonacci_optimized(long int index,
                                  std::map<long int, long int> &memo) {
  auto memo_item = memo.find(index);
  if (memo_item != memo.end())
    return memo_item->second;
  if (index <= 2)
    return 1;
  memo[index] = this->_fibonacci_optimized(index - 1, memo) +
                this->_fibonacci_optimized(index - 2, memo);
  return memo[index];
}
