// Date: 29-09-22
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
  int n, k;
  string s;
  cin >> n >> k >> s;
  int ans = 0;

  auto doit = [&](char c) {
    debug(c);
    int i = 0, j = 0;
    int cnt = 0;
    while (j < n) {
      int prev_j = j;
      while (j < n && (cnt < k || s[j] != c)) {
        cnt += s[j] == c;
        j++;
      }

      if (j == prev_j)
        j++, i = j, cnt = 0;

      debug(i, j);
      ans = max(ans, j - i);

      while (i < j && cnt >= k) {
        cnt -= s[i] == c;
        i++;
      }
    }
  };

  doit('a');
  doit('b');
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t_cases = 1;
  // cin >> t_cases;
  while (t_cases--) {
    solve();
  }
  return 0;
}
