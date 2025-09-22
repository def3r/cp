#include "dbg.h"
#include <unordered_map>

struct Node {
  int key, value;
  Node *next, *prev;

  Node(int k, int v) {
    key = k, value = v;
    next = nullptr, prev = nullptr;
  }

  void disconnect() {
    this->prev->next = next;
    this->next->prev = prev;
  }
};

class LRUCache {
public:
  LRUCache(int capacity) {
    head = new Node(-1, -1);
    tail = new Node(-1, -1);
    head->next = tail;
    tail->prev = head;
    this->capacity = capacity;
  }

  int get(int key) {
    if (m.find(key) == m.end())
      return -1;
    m[key]->disconnect();
    insertAtHead(m[key]);
    return m[key]->value;
  }

  void put(int key, int value) {
    if (m.find(key) != m.end()) {
      m[key]->value = value;
      m[key]->disconnect();
      insertAtHead(m[key]);
      return;
    }
    Node *temp = 0;
    if (m.size() == capacity) {
      temp = tail->prev;
      temp->disconnect();
      m.erase(temp->key);
      delete temp;
    }
    temp = new Node(key, value);
    insertAtHead(temp);
    m[key] = temp;
  }

private:
  void insertAtHead(Node *node) {
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
  }

  Node *head, *tail;
  unordered_map<int, Node *> m = {};
  int capacity = 0;
};

#undef dbg_test_fun
int main() {
  LRUCache *lru = new LRUCache(2);
  lru->put(1, 1);
  lru->put(2, 2);
  cout << lru->get(1) << endl;
  lru->put(3, 3);
  cout << lru->get(2) << endl;

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
