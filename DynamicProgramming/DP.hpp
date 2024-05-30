#ifndef DP_H
#define DP_H
#include <iostream>
#include <map>
class DP {
public:
  long int fibonacci(long int index, bool optimized = true);

private:
  long int _fibonacci(long int index);
  long int _fibonacci_optimized(long int index,
                                std::map<long int, long int> &memo);
};
#endif
