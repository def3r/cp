#include "dbg.h"
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteMiddle(ListNode *head) {
  if (head == nullptr || head->next == nullptr) {
    delete head;
    return nullptr;
  }

  ListNode *slow = head;
  ListNode *fast = head->next->next;
  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }
  ListNode *t = slow->next;
  slow->next = t->next;
  delete t;
  return head;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
