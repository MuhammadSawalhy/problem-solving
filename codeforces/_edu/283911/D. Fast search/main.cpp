// Date: 30-09-22
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
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  sort(a.begin(), a.end());
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << upper_bound(a.begin(), a.end(), r) - lower_bound(a.begin(), a.end(), l) << " ";
  }
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
