#include "dbg.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
  ListNode dummyNode = ListNode(-1);
  ListNode *it = &dummyNode;

  while (list1 != nullptr && list2 != nullptr) {
    if (list1->val <= list2->val) {
      it->next = list1;
      list1 = list1->next;
    } else {
      it->next = list2;
      list2 = list2->next;
    }
  }
  if (list1 != nullptr) {
    it->next = list1;
  } else {
    it->next = list2;
  }
  return dummyNode.next;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
