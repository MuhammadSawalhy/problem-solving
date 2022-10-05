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

int n, k;
string s;

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

  vector<int> nearest_one(n, INT_MAX);
  doit();
  k--;

  if (k == 0) {
    cout << s << endl;
    return;
  }

  int j = -1.4e9;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1')
      j = i;
    nearest_one[i] = min(nearest_one[i], i - j);
  }

  j = 1.4e9;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '1')
      j = i;
    nearest_one[i] = min(nearest_one[i], j - i);
  }

  for (int i = 0; i < n; i++) {
    if (k < nearest_one[i])
      putchar('0');
    else
      putchar((k - nearest_one[i]) & 1 ? '0' : '1');
  }

  putchar(10);
}

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
