#include "../includes/DP.hpp"

int DPSolutions::climb_stairs(int n) {
  std::map<int, int> memo;
  return this->_climb_stairs(n, memo);
}
int DPSolutions::_climb_stairs(int n, std::map<int, int> &memo) {
  auto memo_item = memo.find(n);
  if (memo_item != memo.end())
    return memo[n];
  if (n <= 3)
    return n;
  memo[n] = this->_climb_stairs(n - 1, memo) + this->_climb_stairs(n - 2, memo);
  return memo[n];
}
