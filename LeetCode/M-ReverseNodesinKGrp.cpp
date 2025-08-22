#include "dbg.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// O(N) space because of recursion
ListNode *reverseK(ListNode *head, int k) {
  ListNode *begin = head;
  ListNode *it = head;
  ListNode *end = 0;
  int count = k;
  while (count-- && it != nullptr) {
    it = it->next;
  }
  if (count >= 0) {
    return head;
  }

  end = it;
  it = begin;
  ListNode *next = begin;
  ListNode *prev = 0;
  while (it != end) {
    next = it->next;
    it->next = prev;
    prev = it;
    it = next;
  }
  begin->next = reverseK(end, k);
  return prev;
}
// ListNode *reverseKGroup(ListNode *head, int k) {
//   return reverseK(head, k);
// }

// O(1) Space
ListNode *getKthNode(ListNode *begin, int k) {
  if (begin == 0) {
    return 0;
  }
  while (--k && begin != nullptr) {
    begin = begin->next;
  }
  return begin;
}

ListNode *reverse(ListNode *head) {
  ListNode *it = head;
  ListNode *next = head;
  ListNode *prev = nullptr;
  while (it != nullptr) {
    next = it->next;
    it->next = prev;
    prev = it;
    it = next;
  }
  return prev;
}

ListNode *reverseKGroup(ListNode *head, int k) {
  ListNode *begin = head;
  ListNode *kthNode = getKthNode(begin, k);
  ListNode *prevBegin = 0;
  ListNode *next = 0;

  while (kthNode != 0) {
    next = kthNode->next;
    kthNode->next = 0;
    reverse(begin);
    if (prevBegin != 0) {
      prevBegin->next = kthNode;
    }
    prevBegin = begin;
    if (begin == head) {
      head = kthNode;
    }
    begin = next;
    kthNode = getKthNode(begin, k);
  }
  if (prevBegin != 0) {
    prevBegin->next = begin;
  }
  return head;
}

void reverseFromTo(ListNode *begin, ListNode *end) {
  ListNode *it = begin;
  ListNode *next = begin;
  ListNode *prev = nullptr;
  ListNode *last = (end == nullptr) ? end : end->next;
  while (it != last) {
    next = it->next;
    it->next = prev;
    prev = it;
    it = next;
  }
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
