#include "dbg.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *oddEvenList(ListNode *head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }
  ListNode *oddHead = head->next;
  ListNode *itEven = head;
  ListNode *itOdd = oddHead;
  ListNode *it = oddHead->next;
  bool isEven = true;
  while (it != nullptr) {
    if (isEven) {
      itEven->next = it;
      itEven = it;
    } else {
      itOdd->next = it;
      itOdd = it;
    }
    it = it->next;
    isEven = !isEven;
  }
  itEven->next = oddHead;
  itOdd->next = nullptr;
  return head;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
