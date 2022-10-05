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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  double s = 0, e = 1e8;

  auto valid = [&](double l) {
    int cnt = 0;
    for (int i = 0; i < n; i++)
      cnt += a[i] / l;
    return cnt >= k;
  };

  while (e - s > 1e-7) {
    double mid = (s + e) / 2;
    if (valid(mid)) {
      s = mid;
    } else {
      e = mid;
    }
  }

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
