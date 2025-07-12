#include <bits/stdc++.h>
#include <iostream>
#include <strings.h>
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

void sortColors(vector<int> &nums) {
  int index = 0;
  vector<int> freq = {0, 0, 0};
  for (int num : nums) {
    freq[num]++;
  }
  for (int i = 0; i < 3; i++) {
    for (; freq[i]; freq[i]--) {
      nums[index++] = i;
    }
  }
}

int main() {
  __setup();

  int t;
  cin >> t;

  while (t--) {
  }

  return 0;
}
