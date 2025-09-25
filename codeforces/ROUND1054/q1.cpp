#include <iostream>
#include <unordered_map>

using namespace std;

#undef dbg_test_fun
int main() {
  int t;
  int n, a;

  cin >> t;
  while (t--) {
    cin >> n;
    unordered_map<int, int> freq = {};
    while (n--) {
      cin >> a;
      freq[a]++;
    }
    int count = 0;
    count += freq[0];
    count += (freq[-1] & 1) * 2;
    cout << count << endl;
  }

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
