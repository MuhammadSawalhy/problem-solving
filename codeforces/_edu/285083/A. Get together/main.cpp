// Date: 01-10-22
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
  int x[n];
  int v[n];
  for (int i = 0; i < n; i++)
    cin >> x[i] >> v[i];

  auto valid = [&](double t) {
    double mn = 1e10, mx = -1e10;
    for (int i = 0; i < n; i++) {
      mn = min(mn, (double)x[i] + v[i] * t); // min for right
      mx = max(mx, (double)x[i] - v[i] * t); // max for left
    }
    return mx <= mn;
  };

  double s = 0, e = 1e10;
  while (e - s > 1e-7) {
    double mid = (s + e) / 2;
    if (valid(mid)) {
      e = mid;
    } else {
      s = mid;
    }
  }

  // now we have min time with 1e-6 precision
  cout << fixed << s << endl;
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
