#include "dbg.h"

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
