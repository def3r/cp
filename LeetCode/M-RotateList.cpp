#include "dbg.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int lenLL(ListNode *head) {
  int count = 0;
  while (head != nullptr) {
    count++;
    head = head->next;
  }
  return count;
}

ListNode *rotateRight(ListNode *head, int k) {
  if (head == 0) {
    return 0;
  }
  int len = lenLL(head);
  int idx = len - (k % len);
  if (idx == len) {
    return head;
  }

  ListNode *it = head;
  ListNode *next = 0;
  while (--idx) {
    it = it->next;
  }
  next = it->next;
  it->next = 0;
  it = next;
  while (it->next != 0) {
    it = it->next;
  }
  it->next = head;
  return next;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
