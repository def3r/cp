#include "dbg.h"
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *middleNode(ListNode *head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }
  ListNode *mid = head->next;
  ListNode *it = mid->next;
  bool shift = false;
  while (it != nullptr) {
    if (shift) {
      mid = mid->next;
    }
    it = it->next;
    shift = !shift;
  }
  return mid;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
