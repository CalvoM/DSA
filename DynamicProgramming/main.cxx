#include "DP.hpp"

int main(int argc, char **argv) {
#ifdef DP_OPT
  bool optimized = true;
#else
  bool optimized = false;
#endif
  DP dp_program;
  std::cout << dp_program.fibonacci(10, optimized) << std::endl;
  std::cout << dp_program.fibonacci(20, optimized) << std::endl;
  std::cout << dp_program.fibonacci(30, optimized) << std::endl;
  std::cout << dp_program.fibonacci(40, optimized) << std::endl;
  std::cout << dp_program.fibonacci(50, optimized) << std::endl;
  std::cout << dp_program.fibonacci(60, optimized) << std::endl;
  std::cout << dp_program.fibonacci(100, optimized) << std::endl;
}
