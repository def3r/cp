#include "dbg.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode *prev;
  ListNode() {
    val = 0;
    next = NULL;
    prev = NULL;
  }
  ListNode(int data1) {
    val = data1;
    next = NULL;
    prev = NULL;
  }
  ListNode(int data1, ListNode *next1, ListNode *prev1) {
    val = data1;
    next = next1;
    prev = prev1;
  }
};

ListNode *deleteDuplicates(ListNode *head) {
  if (head == 0) {
    return 0;
  }
  ListNode dummyNode(INT_MIN, head, 0);
  ListNode *it = &dummyNode;

  while (it != 0 && it->next != 0) {
    if (it->val == it->next->val) {
      it->next = it->next->next;
      if (it->next)
        it->next->prev = it;
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
