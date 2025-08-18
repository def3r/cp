#include "dbg.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  ListNode *head = l1, *prev = l1;
  int carry = 0;
  while (l1 != nullptr || l2 != nullptr || carry != 0) {
    int n2 = 0;
    if (l2 != nullptr) {
      n2 = l2->val;
      l2 = l2->next;
    }
    int sum = n2 + carry;
    if (l1 != nullptr) {
      sum += l1->val;
      l1->val = (sum) % 10;
    } else {
      ListNode *newNode = new ListNode((sum) % 10);
      prev->next = newNode;
      l1 = newNode;
    }
    carry = (sum) / 10;
    prev = l1;
    l1 = l1->next;
  }
  return head;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
