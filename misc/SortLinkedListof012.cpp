#include "dbg.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode() {
    val = 0;
    next = NULL;
  }
  ListNode(int data1) {
    val = data1;
    next = NULL;
  }
  ListNode(int data1, ListNode *next1) {
    val = data1;
    next = next1;
  }
};

// Or just use count sortt
ListNode *sortList(ListNode *head) {
  if (head == nullptr) {
    return head;
  }
  ListNode *heads[3] = {0, 0, 0};
  ListNode *its[3] = {0, 0, 0};
  ListNode *it = head;
  while (it != nullptr) {
    if (heads[it->val] == 0) {
      heads[it->val] = it;
      its[it->val] = it;
    } else {
      its[it->val]->next = it;
      its[it->val] = it;
    }
    it = it->next;
  }

  ListNode *h = nullptr, *tail = nullptr;
  for (ListNode *node : heads) {
    if (node == nullptr) {
      continue;
    }
    if (h == nullptr) {
      h = node;
      tail = its[h->val];
    } else {
      tail->next = node;
      tail = its[node->val];
    }
  }
  if (tail != nullptr) {
    tail->next = nullptr;
  }
  return h;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
