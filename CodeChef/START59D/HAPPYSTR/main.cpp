// Date: 05-10-22
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

void solve() {
  string s;
  cin >> s;

  set<char> v = {'a', 'e', 'o', 'i', 'u'};
  for (int i = 2; i < (int)s.size(); i++) {
    if (v.count(s[i]) && v.count(s[i - 1]) && v.count(s[i - 2])) {
      cout << "Happy" << endl;
      return;
    }
  }

  cout << "Sad" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
