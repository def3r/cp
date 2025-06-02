#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
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

string entityParser(string text) {
  unordered_map<string, string> specialChars;
  specialChars["&quot;"] = "\"";
  specialChars["&apos;"] = "'";
  specialChars["&amp;"] = "&";
  specialChars["&gt;"] = ">";
  specialChars["&lt;"] = "<";
  specialChars["&frasl;"] = "/";

  char *ptr = &text[0];
  char *begin = ptr;
  stringstream ss;
  for (; *ptr != 0; ptr++) {
    if (*ptr == '&') {
      begin = ptr;
      while (*ptr != 0 && *ptr != ';')
        ptr++;
      if (*ptr == ';') {
        string specialChar(begin, ptr + 1);
        if (specialChars.find(specialChar) != specialChars.end()) {
          ss << specialChars[specialChar];
          begin = ptr;
          continue;
        }
      }
      ss << *begin;
      ptr = begin;
      continue;
    }
    ss << *ptr;
  }

  cout << "result: " << ss.str() << "\n";

  return "";
}

int main() {
  __setup();

  int t;
  cin >> t;
  cout << t << "\n";

  string text;
  getline(cin, text);
  while (t--) {
    getline(cin, text);
    entityParser(text);
  }

  return 0;
}
