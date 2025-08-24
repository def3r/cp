#include "dbg.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeElements(ListNode *head, int val) {
  if (head == 0) {
    return 0;
  }
  ListNode dummyNode(-1, head);
  ListNode *it = &dummyNode;

  while (it != 0 && it->next != 0) {
    if (it->next->val == val) {
      it->next = it->next->next;
    } else {
      it = it->next;
    }
  }

  return dummyNode.next;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
