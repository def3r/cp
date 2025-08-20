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

int add1(ListNode *node) {
  if (node == nullptr) {
    return 1;
  }
  int sum = node->val + add1(node->next);
  node->val = sum % 10;
  return sum / 10;
}

ListNode *addOne(ListNode *head) {
  int carry = add1(head);
  return (carry != 0) ? new ListNode(carry, head) : head;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
