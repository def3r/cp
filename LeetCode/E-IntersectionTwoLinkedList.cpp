#include "dbg.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// How is this optimal
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  ListNode *d1 = headA;
  ListNode *d2 = headB;
  while (d1 != d2) {
    d1 = d1->next;
    d2 = d2->next;

    if (d1 == d2)
      return d1;

    if (d1 == nullptr)
      d1 = headB;
    if (d2 == nullptr)
      d2 = headA;
  }
  return d1;
}

ListNode *getIntersectionNodeMapSol(ListNode *headA, ListNode *headB) {
  unordered_set<ListNode *> m = {};
  while (headA != nullptr) {
    m.insert(headA);
    headA = headA->next;
  }
  while (headB != nullptr) {
    if (m.find(headB) != m.end()) {
      return headB;
    }
    headB = headB->next;
  }
  return nullptr;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
