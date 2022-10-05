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
  long long w, h, n;
  cin >> w >> h >> n;
  long long s = 0, e = 1e18;
  auto valid = [&](long long x) {
    long long cnt = 0;
    for (long long i = 1; i <= (x / h); i++) {
      cnt += (x / w);
      if (cnt >= n)
        return true;
    }
    return false;
  };
  while (s < e) {
    long long mid = (s + e) >> 1;
    debug(s, e, mid);
    if (valid(mid)) {
      e = mid;
    } else {
      s = mid + 1;
    }
  }
  cout << s << endl;
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
