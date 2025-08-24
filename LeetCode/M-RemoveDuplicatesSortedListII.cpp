#include "dbg.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *nextPtr(ListNode *head, int val) {
  ListNode *it = head;
  while (it && it->val == val) {
    it = it->next;
  }
  return it;
}

ListNode *deleteDuplicates(ListNode *head) {
  if (head == 0) {
    return 0;
  }
  ListNode dummyNode(INT_MIN, head);
  ListNode *it = &dummyNode;
  ListNode *prev = it;

  while (it != 0 && it->next != 0) {
    if (it->val == it->next->val) {
      it = nextPtr(it, it->val);
      prev->next = it;
    } else {
      prev = it;
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
