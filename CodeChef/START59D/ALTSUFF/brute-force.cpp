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

string s;
int n, k;

void doit() {
  string old = s;
  for (int i = 0; i < n; i++) {
    if (old[i] == '0')
      continue;

    s[i] = '0';
    if (i > 0 && old[i - 1] == '0')
      s[i - 1] = '1';
    if (i < n && old[i + 1] == '0')
      s[i + 1] = '1';
  }
}

void solve() {
  cin >> n >> k >> s;

  debug(s);
  while (k--) {
    doit();
    debug(s);
  }

  cout << s << endl;
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
