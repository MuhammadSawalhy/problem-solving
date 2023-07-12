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
  int n;
  cin >> n;
  vector<long long> x(n);
  vector<long long> r(n);
  vector<long long> l(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    r[i] = l[i] = x[i];
  }
  
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    l[i] -= t;
    r[i] += t;
  }

  long long mn = LONG_LONG_MAX, mx = LONG_LONG_MIN;
  for (int i = 0; i < n; i++) {
    mn = min(mn, l[i]);
    mx = max(mx, r[i]);
  }

  cout << 0.5 * (mn + mx) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  cout << fixed;
  int t_cases = 1;
  cin >> t_cases;
  while (t_cases--) {
    solve();
  }
  return 0;
}
