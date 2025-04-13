#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

#define fast_io()                                                              \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()

void __setup() {
  fast_io();

#ifndef ONLINE_JUDGE
  freopen("_input.txt", "r", stdin);
  // freopen("_output.txt", "w", stdout);
#endif
}

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    this->input = std::move(nums);
    output = {};
    result = {};
    ifcan(target, input.begin(), 4);
    return this->result;
  }

  void ifcan(long long target, const vector<int>::iterator &iterator,
             int size) {
    if (size == 1) {
      if (find(iterator, input.end(), target) != input.end()) {
        for (const auto &out : output) {
          cout << out << "\t";
        }
        cout << target << "\n";
        output.push_back(target);
        result.push_back(output);
        output.pop_back();
        return;
      }
      return;
    }
    for (auto it = iterator; it != input.end(); ++it) {
      if (it != iterator && *it == *(it - 1))
        continue;
      output.push_back(*it);
      ifcan(target - *it, it + 1, size - 1);
      output.pop_back();
    }
  }

private:
  vector<vector<int>> result = {};
  vector<int> input = {}, output = {};
};

int main() {
  __setup();

  int t;
  cin >> t;
  Solution s;

  while (t--) {
    int len, target;
    vector<int> v;

    cin >> target >> len;
    while (len--) {
      int temp;
      cin >> temp;
      v.push_back(temp);
    }
    cout << "For target: " << target << "\n";
    s.fourSum(v, target);
    cout << "\n";
  }

  return 0;
}
