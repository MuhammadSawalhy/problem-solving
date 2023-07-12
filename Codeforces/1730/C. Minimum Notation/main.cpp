// Date: 25-09-22
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

  char m = s[s.size() - 1];
  for (int i = (int)s.size() - 2; i >= 0; i--) {
    debug(i, s[i], m);
    if (s[i] > m) {
      s[i] = min((int)'9', (int)s[i] + 1);
    }
    m = min(m, s[i]);
  }

  sort(s.begin(), s.end());
  cout << s << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t_cases = 1;
  cin >> t_cases;
  while (t_cases--) {
    solve();
  }
  return 0;
}
