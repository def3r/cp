#include "dbg.h"

class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

Node *copyRandomList(Node *head) {
  if (head == 0) {
    return head;
  }
  Node dummyHead(1);
  Node *it = &dummyHead;
  Node *temp = head;
  for (; head != 0; head = temp, it = it->next) {
    it->next = head;
    it = head;
    temp = it->next;
    it->next = new Node(head->val);
    it->next->random = head->random;
  }

  it = dummyHead.next;
  temp = it->next;
  while (temp != 0) {
    if (temp->random) {
      temp->random = temp->random->next;
    }
    temp = (temp->next) ? temp->next->next : temp->next;
  }

  head = it->next;
  while (it->next != 0) {
    temp = it->next;
    it->next = it->next->next;
    it = temp;
  }

  return head;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
