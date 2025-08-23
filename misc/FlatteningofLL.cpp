#include "dbg.h"
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode *child;
  ListNode() {
    val = 0;
    next = NULL;
    child = NULL;
  }
  ListNode(int data1) {
    val = data1;
    next = NULL;
    child = NULL;
  }
  ListNode(int data1, ListNode *next1, ListNode *next2) {
    val = data1;
    next = next1;
    child = next1;
  }
};

bool toExit(vector<ListNode *> &heads) {
  for (ListNode *head : heads) {
    if (head != 0) {
      return false;
    }
  }
  return true;
}

int minIdx(vector<ListNode *> &heads) {
  int idx = -1;
  int min_idx = -1;
  for (ListNode *h : heads) {
    idx++;
    if (h == 0)
      continue;
    if (min_idx == -1) {
      min_idx = idx;
    } else if (h->val < heads[min_idx]->val) {
      min_idx = idx;
    }
  }
  return min_idx;
}

ListNode *flattenLinkedList(ListNode *&head) {
  ListNode dummyNode = ListNode(-1);
  ListNode *it = head;

  vector<ListNode *> heads;
  for (it = head; it != nullptr; it = it->next) {
    heads.push_back(it);
  }

  it = &dummyNode;
  while (!toExit(heads)) {
    int min_idx = minIdx(heads);
    it->child = heads[min_idx];
    it = it->child;
    it->next = nullptr;
    heads[min_idx] = heads[min_idx]->child;
  }
  it->child = nullptr;
  return dummyNode.child;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
