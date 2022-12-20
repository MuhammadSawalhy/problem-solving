// Date: 14-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef SAWALHY
#include "debug.hpp"
#endif

struct Char {
  int len = 1;
  int next = -1;
  int index = -1;
  char ch;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  // #ifdef SAWALHY
  //   freopen("input", "r", stdin);
  //   freopen("output", "w", stdout);
  // #endif

  string s;
  cin >> s;

  vector<Char> chars(26);
  vector<Char> elements;
  for (int i = 0; i < 26; i++) {
    chars[i].ch = 'a' + i;
    chars[i].index = i;
    elements.push_back(chars[i]);
  }

  for (int i = (int) s.size() - 1; ~i; i--) {
    // choose the min length [0 ... 25]
    int l = INT_MAX;
    Char next;
    for (auto &c: chars) {
      if (c.len < l) {
        next = c;
        l = c.len;
      }
    }
    Char current;
    current.len = next.len + 1;
    current.next = next.index;
    current.index = elements.size();
    current.ch = s[i];
    elements.push_back(current);
    chars[s[i] - 'a'] = current;
  }

  Char current;
  int l = INT_MAX;
  for (auto &c: chars) {
    if (c.len < l) {
      current = c;
      l = c.len;
    }
  }

  string ans;
  while (current.next != -1) {
    ans += current.ch;
    current = elements[current.next];
  }
  ans += current.ch;

  cout << ans << endl;

  return 0;
}
