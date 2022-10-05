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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  k--;
  while (k--) {
    for (int i = 0; i < n; i++)
      a.push_back(a[i]);
  }

  // debug(a);

  int ans = 0;
  for (int i = 0; i < (int)a.size(); i++) {
    for (int j = i + 1; j < (int)a.size(); j++) {
      ans += a[i] > a[j];
    }
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
