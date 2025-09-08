#include "dbg.h"

bool checkValidStringOptimal(string s) {
  int minOpen = 0;
  int maxOpen = 0;

  for (char c : s) {
    if (c == '(') {
      minOpen++, maxOpen++;
    } else if (c == ')') {
      minOpen = max(minOpen - 1, 0), maxOpen--;
    } else {
      minOpen = max(minOpen - 1, 0);
      maxOpen++;
    }
    if (maxOpen < 0)
      return false;
  }
  return minOpen == 0 || maxOpen == 0;
}

bool checkValidString(string s) {
  stack<char> c;
  int starCount = 0;

  for (char ch : s) {
    switch (ch) {
    case '(':
      c.push('(');
      break;
    case ')':
      starCount = 0;
      while (!c.empty() && c.top() == '*')
        c.pop(), starCount++;
      if (!c.empty())
        c.pop();
      else if (starCount != 0)
        starCount--;
      else
        return false;
      while (starCount-- != 0)
        c.push('*');
      break;
    default: // *
      c.push('*');
    }
  }

  starCount = 0;
  while (!c.empty() && c.top() == '*') {
    c.pop();
    starCount++;
    while (!c.empty() && c.top() == '(' && starCount != 0) {
      c.pop();
      starCount--;
    }
  }

  return c.empty();
}

#undef dbg_test_fun
int main() {
  string s;

#define dbg_test_fun checkValidStringOptimal(s)
  dbg_test_with(true, s = "()");
  dbg_test_with(true, s = "(*)");
  dbg_test_with(true, s = "(*))");
  dbg_test_with(false, s = "(*)(");
  dbg_test_with(false, s = "(((((()*)(*)*))())())(()())())))((**)))))(()())()");
  dbg_test_with(true, s = "((((()(()()()*()(((((*)()*(**(())))))(())()())(((()"
                          ")())())))))))(((((())*)))()))(()((*()*(*)))(*)()");

  return EXIT_SUCCESS;
}
