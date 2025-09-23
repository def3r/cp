#include "dbg.h"

struct Node {
  int key, value, freq;
  Node *next, *prev;

  Node(int k, int v) {
    key = k, value = v, freq = 0;
    next = 0, prev = 0;
  }

  void disconnect() {
    next->prev = prev;
    prev->next = next;
  }
};

struct List {
  int size = 0;
  Node *head = 0;
  Node *tail = 0;

  List() {
    head = new Node(-1, -1);
    tail = new Node(-1, -1);
    head->next = tail;
    tail->prev = head;
  }

  void insertAtHead(Node *node) {
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;

    size++;
  }

  void removeAtTail() {
    Node *temp = tail->prev;

    temp->disconnect();
    delete temp;
    size--;
  }

  int getKeyAtTail() { return (size == 0) ? -1 : tail->prev->key; }
};

class LFUCache {
public:
  LFUCache(int capacity) {
    mL[0] = new List;
    this->capacity = capacity;
  }

  int get(int key) {

    if (m.find(key) == m.end())
      return -1;
    increment(key);
    return m[key]->value;
  }

  void put(int key, int value) {

    if (m.find(key) != m.end()) {
      m[key]->value = value;
      increment(key);
      return;
    }

    if (m.size() == capacity) {
      int minFreq = mL.begin()->first;
      int mfKey = mL[minFreq]->getKeyAtTail();

      mL[minFreq]->removeAtTail();

      m.erase(mfKey);

      checkValidity(minFreq);
    }

    Node *temp = 0;
    temp = new Node(key, value);
    insertAtHead(temp, 0);
    m[key] = temp;
  }

private:
  void insertAtHead(Node *node, int freq) {
    if (mL.find(freq) == mL.end()) {
      mL[freq] = new List;
    }
    mL[freq]->insertAtHead(node);
  }

  void increment(int key) {
    m[key]->disconnect();
    mL[m[key]->freq]->size--;
    checkValidity(m[key]->freq);
    insertAtHead(m[key], ++m[key]->freq);
  }

  void checkValidity(int key) {
    if (mL[key]->size == 0) {
      delete mL[key]->head;
      delete mL[key]->tail;
      delete mL[key];
      mL.erase(key);
    }
  }

  map<int, Node *> m = {};
  map<int, List *> mL = {};
  vector<pair<Node *, Node *>> v = {};
  int capacity = 0;
};

#undef dbg_test_fun
int main() {
  LFUCache *lfu = new LFUCache(2);
  lfu->put(1, 1);              // cache=[1,_], cnt(1)=1
  lfu->put(2, 2);              // cache=[2,1], cnt(2)=1, cnt(1)=1
  cout << lfu->get(1) << endl; // return 1
                               // cache=[1,2], cnt(2)=1, cnt(1)=2
  lfu->put(3, 3); // 2 is the LFU key because cnt(2)=1 is the smallest,
                  // invalidate 2-> cache=[3,1], cnt(3)=1, cnt(1)=2
  cout << lfu->get(2) << endl; // return -1 (not found)
  cout << lfu->get(3) << endl; // return 3
                               // cache=[3,1], cnt(3)=2, cnt(1)=2
  lfu->put(4, 4); // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                  // cache=[4,3], cnt(4)=1, cnt(3)=2
  cout << lfu->get(1) << endl; // return -1 (not found)
  cout << lfu->get(3) << endl; // return 3
                               // cache=[3,4], cnt(4)=1, cnt(3)=3
  cout << lfu->get(4) << endl; // return 4
                               // cache=[4,3], cnt(4)=2, cnt(3)=3

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
