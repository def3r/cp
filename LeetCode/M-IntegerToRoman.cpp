#include <bits/stdc++.h>
#include <cstdlib>
#include <iostream>
#include <strings.h>
#include <utility>
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

class Romanizer {
public:
  Romanizer(const int &n) {
    if (n <= 0 || n >= 4000) {
      cout << "must be b/w 1, 3999\n";
      exit(1);
    }
    this->n = n;
    convert();
    cout << result << "\n";
  }

  void convert() {
    index = 0;
    result = "";
    while (n > 0) {
      result = getRoman(n % 10) + result;
      n /= 10;
      index++;
    }
  }

  string getRoman(int &&n) {
    string result = "";
    if (n >= 1 && n <= 3) {
      while (n--) {
        result = result + roman[index].first;
      }
    } else if (n == 4) {
      result = roman[index].first + roman[index].second;
    } else if (n == 5) {
      result = roman[index].second;
    } else if (n >= 6 && n <= 8) {
      result = roman[index].second;
      while (n-- > 5) {
        result = result + roman[index].first;
      }
    } else if (n == 9) {
      result = roman[index].first + roman[index + 1].first;
    }

    return result;
  }

private:
  int n, index = 0;
  vector<pair<string, string>> roman = {
      {"I", "V"}, {"X", "L"}, {"C", "D"}, {"M", " "}};
  string result = "";
};

int main() {
  __setup();

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    cout << n << ":";
    Romanizer r(n);
  }

  return 0;
}
