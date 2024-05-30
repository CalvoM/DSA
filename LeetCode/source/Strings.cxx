#include "../includes/Strings.hpp"

void StringsSolutions::reverse_str(std::vector<char> &s) {
  int begin = 0, end = s.size() - 1;
  while (begin <= end) {
    char buffer = s[end];
    s[end] = s[begin];
    s[begin] = buffer;
    begin++;
    end--;
  }
}
