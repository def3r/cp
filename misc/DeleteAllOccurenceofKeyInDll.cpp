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

ListNode *deleteAllOccurrences(ListNode *head, int target) {
  if (head == 0) {
    return 0;
  }
  ListNode dummyNode(-1, head, 0);
  head->prev = &dummyNode;
  ListNode *it = head;

  while (it != 0) {
    if (it->val == target) {
      it->prev->next = it->next;
      if (it->next != 0)
        it->next->prev = it->prev;
    }
    it = it->next;
  }

  if (dummyNode.next != 0) {
    dummyNode.next->prev = 0;
  }
  return dummyNode.next;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
