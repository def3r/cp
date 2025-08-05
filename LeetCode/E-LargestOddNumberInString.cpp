#include "dbg.h"

string largestOddNumber(string num) {
  int end = num.size() - 1;
  while (end >= 0 && (num[end] - '0') % 2 == 0) {
    end--;
  }
  return (end < 0) ? "" : num.substr(0, end + 1);
}

#undef dbg_test_fun
int main() {
  string num;

#define dbg_test_fun largestOddNumber(num)
  dbg_test_with("5", num = "52");
  dbg_test_with("", num = "4206");
  dbg_test_with("35427", num = "35427");

  return EXIT_SUCCESS;
}
