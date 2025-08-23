#include "dbg.h"

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// HeapSort
// but O(N) space
ListNode *sortList(ListNode *head) {
  priority_queue<int, vector<int>, greater<int>> pq;
  ListNode *it = 0;
  for (it = head; it != nullptr; it = it->next)
    pq.push(it->val);

  for (it = head; !pq.empty(); it = it->next) {
    it->val = pq.top(), pq.pop();
  }

  return head;
}

ListNode *midNode(ListNode *head) {
  if (head == 0 || head->next == 0) {
    return head;
  }
  ListNode *slow = head;
  ListNode *fast = head;
  while (fast->next != 0 && fast->next->next != 0) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

ListNode *mergeSort(ListNode *leftHead) {
  if (leftHead == 0 || leftHead->next == 0) {
    return leftHead;
  }

  ListNode *rightHead = midNode(leftHead);
  ListNode *it = rightHead;
  rightHead = rightHead->next;
  it->next = 0;

  leftHead = mergeSort(leftHead);
  rightHead = mergeSort(rightHead);

  ListNode dummyNode = ListNode(-1);
  it = &dummyNode;
  while (leftHead != nullptr && rightHead != nullptr) {
    if (leftHead->val <= rightHead->val) {
      it->next = leftHead;
      leftHead = leftHead->next;
    } else {
      it->next = rightHead;
      rightHead = rightHead->next;
    }
    it = it->next;
  }
  if (leftHead != 0) {
    it->next = leftHead;
  } else {
    it->next = rightHead;
  }
  return dummyNode.next;
}

// Merge sort type shi
// O (nlogn) time, altho, O (logN) space (rec stack with min height log N)
ListNode *sortListMerge(ListNode *head) { return mergeSort(head); }

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
