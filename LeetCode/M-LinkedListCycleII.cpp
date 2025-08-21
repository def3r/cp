#include "dbg.h"
#include <unordered_set>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// This is good, its real good
ListNode *detectCycleOptimal(ListNode *head) {
  if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
    return nullptr;
  }
  ListNode *slow = head;
  ListNode *fast = head;
  while (fast->next != nullptr && fast->next->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {
      slow = head;
      while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
      }
      return slow;
    }
  }
  return nullptr;
}

ListNode *detectCycle(ListNode *head) {
  unordered_set<ListNode *> s;
  while (head != nullptr) {
    if (s.find(head) != s.end()) {
      return head;
    }
    s.insert(head);
    head = head->next;
  }
  return nullptr;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
