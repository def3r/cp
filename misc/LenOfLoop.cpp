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

int findLengthOfLoop(ListNode *head) {
  if (head == 0 || head->next == 0) {
    return 0;
  }
  int count = 0;
  ListNode *slow = head;
  ListNode *fast = head;
  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {
      slow = head;
      while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
      }
      fast = fast->next;
      count++;
      while (slow != fast) {
        fast = fast->next;
        count++;
      }
      return count;
    }
  }
  return 0;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
