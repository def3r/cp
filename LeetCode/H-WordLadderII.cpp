#include "dbg.h"
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

void dfs(string word, const string &bWord, vector<string> seq,
         vector<vector<string>> &res, unordered_map<string, int> &m) {
  if (word == bWord) {
    reverse(seq.begin(), seq.end());
    res.push_back(seq);
    return;
  }

  int val = m[word];
  for (int i = 0; i < word.size(); i++) {
    char original = word[i];
    for (char c = 'a'; c <= 'z'; c++) {
      word[i] = c;
      if (m.find(word) != m.end() && m[word] + 1 == val) {
        seq.push_back(word);
        dfs(word, bWord, seq, res, m);
        seq.pop_back();
      }
    }
    word[i] = original;
  }
}

vector<vector<string>> findLadders(string beginWord, string endWord,
                                   vector<string> &wordList) {
  int n = wordList.size(), ws = wordList[0].size();
  vector<vector<string>> res;
  unordered_set<string> s(wordList.begin(), wordList.end());
  unordered_map<string, int> m;
  queue<pair<string, int>> q;
  int lvl = 1;
  if (s.find(endWord) == s.end())
    return {};

  q.push({beginWord, 1});
  m[beginWord] = 1;
  s.erase(beginWord);
  while (!q.empty()) {
    pair<string, int> front = q.front();
    q.pop();

    lvl = max(lvl, front.second);
    for (int i = 0; i <= ws; i++) {
      char original = front.first[i];
      for (char c = 'a'; c <= 'z'; c++) {
        front.first[i] = c;
        if (s.find(front.first) != s.end()) {
          q.push({front.first, front.second + 1});
          m[front.first] = front.second + 1;
          s.erase(front.first);
        }
      }
      front.first[i] = original;
    }
  }

  dfs(endWord, beginWord, {endWord}, res, m);

  return res;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
