#include "../includes/DP.hpp"
#include <algorithm>
#include <catch2/catch_message.hpp>
#include <iostream>
#include <set>

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
int DPSolutions::max_profit(std::vector<int> &prices) {
  int profit = 0;
  int current_profit = 0;
  std::map<int, int> memo;
  for (int p = 0; p < prices.size(); p++) {
    // if it the largest then current profit 0
    if (*std::max_element(prices.begin() + p, prices.end()) == prices[p]) {
      current_profit = 0;
      continue;
    }
    current_profit = this->_max_profit(prices[p], p, prices, memo);
    if (current_profit > profit)
      profit = current_profit;
  }
  return profit;
}
int DPSolutions::_max_profit(int current_price, int price_pos,
                             std::vector<int> &prices,
                             std::map<int, int> &memo) {
  auto memo_item = memo.find(current_price);
  if (memo_item != memo.end())
    return memo[current_price];

  int profit = 0;
  for (int p = price_pos + 1; p < prices.size(); p++) {
    auto price = prices[p];
    int current_profit = price - current_price;
    if (current_profit > profit)
      profit = current_profit;
  }
  memo[current_price] = profit;
  return profit;
}

long int DPSolutions ::fib_tab(long int index) {
  long int fib_num = 1;
  std::vector<long int> fib_tabs;
  for (int k = 0; k <= index; k++) {
    if (k == 0 or k == 1) {
      fib_tabs.push_back(k);

    } else {
      fib_num = fib_tabs[k - 1] + fib_tabs[k - 2];
      fib_tabs.push_back(fib_num);
    }
  }
  return fib_num;
}
std::vector<std::vector<int>>
DPSolutions::combination_sum(std::vector<int> &candidates, int target) {
  std::vector<std::vector<int>> target_combinations;
  std::set<std::vector<int>> unique_combinations;
  for (auto c : candidates) {
    int new_target = target - c;
    std::vector<int> combination;
    bool is_okay = this->_combination_sum(candidates, combination, new_target);
    if (is_okay == true) {
      combination.push_back(c);
      target_combinations.push_back(combination);
      unique_combinations.insert(combination);
    }
  }
  for (auto si : unique_combinations) {
    for (auto s : si) {
      std::cout << s << " ";
    }
    std::cout << std::endl;
  }
  return target_combinations;
}

bool DPSolutions::_combination_sum(std::vector<int> &candidates,
                                   std::vector<int> &combination, int target) {
  bool is_okay;
  if (target == 0) {
    return true;
  }
  if (target < 0) {
    return false;
  }
  for (auto c : candidates) {
    int new_target = target - c;
    is_okay = this->_combination_sum(candidates, combination, new_target);
    if (is_okay == true) {
      combination.push_back(c);
      return true;
    }
  }
  return false;
}
