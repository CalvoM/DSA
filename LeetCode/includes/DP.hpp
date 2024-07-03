#ifndef DP_H_
#define DP_H_
#include <map>
#include <vector>
class DPSolutions {
public:
  int climb_stairs(int n);
  int max_profit(std::vector<int> &prices);
  long int fib_tab(long int index);
  std::vector<std::vector<int>> combination_sum(std::vector<int> &candidates,
                                                int target);

private:
  int _climb_stairs(int n, std::map<int, int> &memo);
  int _max_profit(int current_price, int price_pos, std::vector<int> &prices,
                  std::map<int, int> &memo);
  bool _combination_sum(std::vector<int> &candidates,
                        std::vector<int> &combination, int target);
};
#endif
