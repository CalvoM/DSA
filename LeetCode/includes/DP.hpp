#ifndef DP_H_
#define DP_H_
#include <map>
class DPSolutions {
public:
  int climb_stairs(int n);

private:
  int _climb_stairs(int n, std::map<int, int> &memo);
};
#endif
