#include "dbg.h"
#include <algorithm>
#include <iterator>
#include <queue>
#include <vector>

// optimal
int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
  unordered_set<string> s(wordList.begin(), wordList.end());
  if (s.find(endWord) == s.end()) {
    return 0;
  }
  int ws = wordList[0].size();
  queue<pair<string, int>> q{};

  q.push({beginWord, 1});
  s.erase(beginWord);
  while (!q.empty()) {
    pair<string, int> front = q.front();
    q.pop();
    if (front.first == endWord)
      return front.second;

    for (int i = 0; i < ws; i++) {
      char original = front.first[i];
      for (char c = 'a'; c <= 'z'; c++) {
        front.first[i] = c;
        if (s.find(front.first) != s.end()) {
          q.push({front.first, front.second + 1});
          s.erase(front.first);
        }
      }
      front.first[i] = original;
    }
  }

  return 0;
}

// naive
int bfs(vector<vector<int>> &adj, int vertex, int endV) {
  int level = 0;
  queue<int> q{};
  vector<char> visited(adj.size(), 0);

  q.push(vertex);
  visited[vertex] = 1;
  while (!q.empty()) {
    level++;
    int qSize = q.size();
    while (qSize--) {
      int front = q.front();
      q.pop();

      visited[front] = 1;
      for (int v : adj[front]) {
        if (v == endV)
          return level + 1;
        if (!visited[v])
          q.push(v);
      }
    }
  }

  return 0;
}

int ladderLengthLiteralGraph(string beginWord, string endWord,
                             vector<string> &wordList) {
  auto it = find(wordList.begin(), wordList.end(), endWord);
  if (it == wordList.end())
    return 0;
  int n = wordList.size(), ws = wordList[0].size();
  vector<vector<int>> adj(n + 1, vector<int>{});

  int eW = distance(wordList.begin(), it);
  it = find(wordList.begin(), wordList.end(), beginWord);
  int bW = n;
  if (it == wordList.end()) {
    wordList.push_back(beginWord);
    n++;
  } else {
    bW = distance(wordList.begin(), it);
  }

  for (int i = 0; i < n - 1; i++) {
    if (wordList[i] == beginWord)
      bW = i;
    for (int j = i + 1; j < n; j++) {
      int diff = 0;
      for (int k = 0; k < ws; k++) {
        if (wordList[i][k] != wordList[j][k] && ++diff > 1)
          break;
      }
      if (diff == 1) {
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }

  return bfs(adj, bW, eW);
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func
  string beginWord;
  string endWord;
  vector<string> wordList;
  beginWord = "hit", endWord = "cog",
  wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

  cout << ladderLength(beginWord, endWord, wordList);

  return EXIT_SUCCESS;
}
