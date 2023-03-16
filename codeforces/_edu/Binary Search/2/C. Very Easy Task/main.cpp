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

void bs() {
  int n, x, y;
  cin >> n >> x >> y;
  long long s = 0, e = 1e18;
  auto valid = [&](long long t) {
    return (t / min(x, y) + (t - min(x, y)) / max(x, y)) >= n;
  };
  while (s < e) {
    long long mid = (s + e) >> 1;
    if (valid(mid)) {
      e = mid;
    } else {
      s = mid + 1;
    }
  }
  cout << s << endl;
}

long long n, x, y, mn, mx;
inline bool valid(long long t) { return (t / mn + (t - mx) / mx) >= n; };

void solve() {
  cin >> n >> x >> y;
  mn = min(x, y);
  mx = max(x, y);
  long long t = 0;
  while (!valid(t)) {
    t += mn;
  }
  cout << t << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t_cases = 1;
  // cin >> t_cases;
  while (t_cases--) {
    solve();
    // bs();
  }
  return 0;
}
