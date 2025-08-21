#include "dbg.h"
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseList(ListNode *head) {
  if (head == nullptr) {
    return head;
  }
  ListNode *it = head;
  ListNode *prev = nullptr;
  ListNode *next = it->next;
  while (it != nullptr) {
    next = it->next;
    it->next = prev;
    prev = it;
    it = next;
  }
  return prev;
}

// Leetcode Runtime 155ms
// why is this optimal
bool isPalindromeOptimal(ListNode *head) {
  ListNode *slow = head;
  ListNode *fast = head;
  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
  }
  slow = reverseList(slow);
  ListNode *itEnd = slow;
  ListNode *itBeg = head;
  while (itEnd != nullptr) {
    if (itBeg == nullptr) {
      return false;
    }
    if (itEnd->val != itBeg->val) {
      return false;
    }
    itEnd = itEnd->next;
    itBeg = itBeg->next;
  }
  slow = reverseList(slow);
  return true;
}

// O(N) Space
// Leetcode Runtime 0ms
bool isPalindrome(ListNode *head) {
  vector<int> list = {};
  while (head != nullptr) {
    list.push_back(head->val);
    head = head->next;
  }
  int left = 0;
  int right = list.size() - 1;
  while (left <= right) {
    if (list[left] != list[right]) {
      return false;
    }
    left++;
    right--;
  }
  return true;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
