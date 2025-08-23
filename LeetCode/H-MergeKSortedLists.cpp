#include "dbg.h"
#include <queue>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
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

// Least space req
ListNode *mergeKLists(vector<ListNode *> &lists) {
  ListNode dummyNode = ListNode(-1);
  ListNode *it = &dummyNode;
  while (!toExit(lists)) {
    // Instead, prefer min heap (priority_queue)
    int min_idx = minIdx(lists);
    it->next = lists[min_idx];
    it = it->next;
    lists[min_idx] = lists[min_idx]->next;
  }
  it->next = nullptr;
  return dummyNode.next;
}

// This expensive in both space and time
ListNode *recFun(vector<ListNode *> &lists, int idx) {
  if (idx < 0) {
    return 0;
  }
  ListNode *sorted = recFun(lists, idx - 1);
  ListNode dummyNode = ListNode(-1);
  ListNode *it = &dummyNode;
  ListNode *it1 = lists[idx];

  while (sorted != nullptr && it1 != nullptr) {
    if (sorted->val <= it1->val) {
      it->next = sorted;
      sorted = sorted->next;
    } else {
      it->next = it1;
      it1 = it1->next;
    }
    it = it->next;
  }
  if (sorted != 0) {
    it->next = sorted;
  } else {
    it->next = it1;
  }

  return dummyNode.next;
}

ListNode *mergeKListsRecursive(vector<ListNode *> &lists) {
  return recFun(lists, lists.size() - 1);
}

ListNode *mergeKListsOptimal(vector<ListNode *> &lists) {
  auto cmp = [](const ListNode *l, const ListNode *r) {
    return l->val < r->val;
  };
  priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);
  for (ListNode *node : lists) {
    pq.push(node);
  }

  ListNode dummyNode = ListNode(-1);
  ListNode *it = &dummyNode;
  while (!pq.empty()) {
    it->next = pq.top();
    pq.pop();
    it = it->next;
    if (it->next)
      pq.push(it->next);
  }
  it->next = nullptr;
  return dummyNode.next;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
